/* TRACKING POINTERS:
 * 
 * ptr -> x -> 100
 * *ptr = 100 = value of x
 *
 * dptr -> ptr -> x -> 100
 * **dptr = 100 = value of x
 * *dptr = address of x
 * dptr = address of ptr
 *
 * when *dptr (which is the address of x) changes to the address of y
 * then **dptr changes to the value of y -- in this case 25
 * -------------------
 * compile and run with:
 * gcc dp.c
 * #or
 * clang dp.c
 *
 * put in a file:
 * ./a.out > filename
 */

#include <stdio.h>

int main(){

    /* double pointer example */
    int x = 100;
    int *ptr = &x;
    puts("BEFORE THE CHANGE OF ADDRESS");
    printf("the value of x = %d\n", x);
    printf("the address of x given by ptr =  %p\n", ptr);

    int **dptr = &ptr;
    printf("the address of ptr given by dptr =  %p\n", dptr);
    printf("the address of x given by *dptr which tracks ptr =  %p\n", *dptr);
    printf("the value of x given by **dptr =  %d\n", **dptr);

    putchar('\n');
    puts("AFTER THE CHANGE OF ADDRESS");
    puts("i.e., y = 25; *dptr = &y;");
    putchar('\n');

    int y = 25;
    *dptr = &y;

    printf("*dptr is  = %p\n", *dptr);
    printf("**dptr is =  %d\n", **dptr);
    printf("*ptr is  = %d\n", *ptr);

    return 0;
}
