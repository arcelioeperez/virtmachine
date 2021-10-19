#include <stdio.h>
#include <stdint.h>

enum {
    R_RO = 0,
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

uint16_t reg[R_COUNT];

//output is 0...9
int main(){
    for(int i = 0; i < R_COUNT; i++){
        printf("%d", i);
        putchar('\n');
    }
    return 0;
}

