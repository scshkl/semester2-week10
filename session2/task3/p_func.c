
#include <stdio.h>
#include <stdlib.h>

int add( int i, int j );
int subtract(int i, int j);
int multiply(int i, int j);

/* 
 * main: creating and testing function pointers
 */
int main( void ) {

    int (*operation)(int,int);  // function pointer for function with 2 integer arguments, returning an int

    int num1=2, num2=3; // data for arguments

    // compute the sum using the function - print out the operands and answer
    printf("sum using function add(5,6): %d\n", add(5,6));

    // compute the sum using the pointer - print out the operands and answer
    operation = &add;
    printf("sum using pointer operation(7,9): %d\n", operation(7,9));

    // other operations
    operation = &subtract;
    printf("sum using pointer subtract(7,9): %d\n", subtract(7,9));

    operation = &multiply;
    printf("sum using pointer multiply(-7,-9): %d\n", multiply(-7,-9));



    return 0;
}

/*
 * integer operation implementations
 */

int add( int i, int j ) {
    return i+j;
}

int subtract( int i, int j ) {
    return i-j;
}

int multiply(int i, int j){
    return i*j;
}