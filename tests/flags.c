#include <stdio.h>

enum {
    FL_POS = 1 << 0,
    FL_ZRO = 1 << 1,
    FL_NEG = 1 << 2,
};

//when using << or "left shift" operator you are multiplying by 2^N
//i.e., 1 << 2 == 1 * 2^2 == 1 * 4 == 4


//when using >> or "right shift" operator you are dividing by 2^N 


int main(void){
    /*
     FL_POS = 1
     FL_ZRO = 2
     FL_NEG = 4
     */

    printf("FL_POS =%d\n", FL_POS);
    printf("FL_ZRO =%d\n", FL_ZRO);
    printf("FL_NEG =%d\n", FL_NEG);

    return 0;
}
