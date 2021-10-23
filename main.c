/* in progress */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>

/* unix libs */
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

//Trap codes, no this has nothing to do with the music genre
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

//Swap -- remember that: left shift << means multiply times 2^N;
//right shift means >> divide by 2^N;
//the | (bitwise or) means that: if both bits are 0 then 0 - else 1;
//"LC-3 programs are big-endian - therefore we need to swap each uint16 that is
//loaded" - tutorial

uint16_t swap16(uint16_t x){
	return (x << 8) | (x >> 8);
}

void updateFlags(uint16_t x){
	if(reg[r] == 0){
		reg[R_COND] = FL_ZRO;
	}
	//negative numbers in binary start with 1 -- the left most number
	else if(reg[r] >> 15){
		reg[R_COND] = FL_NEG;
	}
	else{
		reg[R_COND] = FL_POS;
	}
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
	

    return 0;
}
