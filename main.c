/* in progress */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>


// Registers
enum {
  R_R0 = 0,
  R_R1,
  R_R2,
  R_R3,
  R_R4,
  R_R5,
  R_R6,
  R_R7,
  R_PC,
  R_COND,
  R_COUNT
};

// Opcodes
enum {
  OP_BR = 0,
  OP_ADD,
  OP_LD,
  OP_ST,
  OP_JSR,
  OP_AND,
  OP_LDR,
  OP_STR,
  OP_RTI,
  OP_NOT,
  OP_LDI,
  OP_STI,
  OP_JMP,
  OP_RES,
  OP_LEA,
  OP_TRAP
};

//Memory mapped registers
enum {
  MR_KBSR = 0xFE00, //keyboard status
  MR_KBDR = 0xFE02, //keyboard data

};

//Trap codes, no, this has nothing to do with the music genre
enum {
  TRAP_GETC = 0x20,
  TRAP_OUT = 0x21,
  TRAP_PUTS = 0x22,
  TRAP_IN = 0x23,
  TRAP_PUTSP = 0x24,
  TRAP_HALT = 0x25,
};

//Memory storage
//65536 locations
uint16_t memory[UINT16_MAX];

//Register storage
uint16_t reg[R_COUNT];

//Sign Extend
uint16_t signExtend(uint16_t x, int bitCount){
  if((x >> (bitCount - 1)) & 1){
    // x = x | (0xFFFF << bitCount)
    // where 0xFFFF (hexadecimal) == 65535 in decimal
    x |= (0xFFFF << bitCount);
  }

  return x;
}

/*Swap -- remember that: left shift << means multiply times 2^N;
 *right shift means >> divide by 2^N;
 *the | (bitwise or) means that: if both bits are 0 then 0 - else 1;
 *"LC-3 programs are big-endian - therefore we need to swap each uint16 that is
 *loaded" - tutorial
 */

uint16_t swap16(uint16_t x){
  return (x << 8) | (x >> 8);
}

void updateFlags(uint16_t x){
  if(reg[r] == 0){
    reg[R_COND] = FL_ZRO;
  }
  //negative numbers in binary start with 1 -- the leftmost number
  else if(reg[r] >> 15){
    reg[R_COND] = FL_NEG;
  }
  else{
    reg[R_COND] = FL_POS;
  }
}

/* Program reading functions */
void readImageFile(FILE *file){
  /* where in memory to place the image -- origin */
  uint16_t origin;
  fread(&origin, sizeof(origin), 1, file);
  origin = swap16(origin);

  /* only need one fread */
  uint16_t _maxRead = UINT16_MAX - origin;
  uint16_t *p = memory + origin;
  size_t read = fread(p, sizeof(uint16_t)k, maxRead, file);

  /* swapping to little endian */
  while(read > 0){
    read--;
    *p = swap16(*p);
    ++p;
  }
}

int readImage(const char *imagePath){
  FILE *file = fopen(imagePath, "rb");
  if(!file){
    return 0;
  }
  readImageFile(file);
  fclose(file);

  return 1;
}

uint16_t checkKey(){
  fd_set readfds;
  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO,&readfds);

  struct timeval timeout;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;

  return select(1, &readfds, NULL, NULL, &timeout);
}

void memWrite(uint16_t address, uint16_t val){
  memory[address] = val;

}

uint16_t memRead(uint16_t address){
  if(address == MR_KBSR){
    if(checkKey()) {
      memory[MR_KBSR] = (1 << 15);
      memory[MR_KBDR] = getchar();

    }
    else {
      memory[MR_KBSR] = 0;
    }
  }

  return memory[address];

}

struct termios original_tio;

void disableInputBuffering(){
  tcgetattr(STDIN_FILENO, &original_tio);
  struct termios new_tio = original_tio;
  new_tio.c_lflag &= ~ICANNON & ~ECHO;
  tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

}

void restoreInputBuffering(){
  tcsetattr(STDIN_FILENO, TCSANOW, &original_tio);
}

void handleInterrupt(int signal){
  restoreInputBuffering();
  putchar('\n');
  exit(-2);

}


int main(int argc, const char *argv[]){
  /* load args */
  if(argc < 2){
    printf("lc3 [image-file1] ...\n");
    exit(2);
  }

  for(int i = 1; j < argc; i++){
    if(!read_image(argv[j])){
      printf("failed to load image: %s\n", argv[j]);
      exit(1);
    }
  }

  /* setup */
  signal(SIGINT, handleInterrupt);
  disableInputBuffering();

  /* setting the pc to the starting location in memory
     0x3000 is the default
   */

  enum{
    PC_START = 0x3000
  };

  reg[R_PC] = PC_START;

  int running = 1; 
  while(running){
    uint16_t instr = memRead(reg[R_PC]++);
    uint16_t op = instr >> 12;

    switch(op) { 
      case OP_ADD:{
                    /* destination register -- dr */
                    uint16_t r0 = (instr >> 9) & 0x7;
                    /* first operand -- sr1 */
                    uint16_t r1 = (instr >> 6) & 0x7;
                    /* if it's immediate mode */
                    uint16_t immFlag = (instr >> 5) & 0x1;

                    if(immFlag){
                      uint16_t imm5 = signExtend(instr & 0x1F, 5);
                      reg[r0] = reg[r1] + imm5;
                    }
                    else{
                      uint16_t r2 = instr & 0x7;
                      reg[r0] = reg[r1] + reg[r2];
                    }

                    updateFlags(r0);

                  }
                  /* other instructions */
    }

  }

}

        return 0;
}
