/* in progress */

#include <stdio.h>

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
    MR_KBDR = 0xFE02,

};

//Trap codes, no this is not the music genre
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

int main(){
    return 0;
}
