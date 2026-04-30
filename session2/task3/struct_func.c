
#include <stdio.h>
#include <stdlib.h>

/*
 * structure definition
 */
typedef struct _functions {
    int (*operations[3])(int,int);   // function pointer
    char symbols[3];                 // function symbol
} Functions;

/*
 * function headers
 */
int add( int i, int j );
int subtract( int i, int j );
int multiply( int i, int j );
Functions *setFunctions( void );

/*
 * populate the struct with function pointers
 */
Functions *setFunctions( void ) {
    Functions *functions = malloc(sizeof(Functions));
    functions->operations[0] = add;
    functions->symbols[0] = '+';
    functions->operations[1] = subtract;
    functions->symbols[1] =  '-';
    functions->operations[2] = multiply;
    functions->symbols[2] = '*';
    return functions;
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

int multiply( int i, int j ) {
    return i*j;
}

/* 
 * main: creating and testing structures containing function pointers
 */
int main( int argc, char* argv[] ) {

    Functions *myFunctions = setFunctions();

    int num1=2, num2=3;   // arguments 2,3

    // write code to loop through the 3 functions and print an appropriate sum for each, eg. "2 + 3 = 5"
    // use the structure symbol and function-pointer data rather than hard-coding values

    for(int i=0; i<3; ++i){
        printf("operation %c, result: %d\n", myFunctions->symbols[i], myFunctions->operations[i](num1, num2));
    }

    if (argc == 4){
        int n1 = atoi(argv[1]);
        char sym = argv[2][0];
        int n2 = atoi(argv[3]);

        printf("opration %c\n", sym);

        switch(sym){
            case '+':
                printf("results of %d %c %d = %d\n", n1, 
                    sym, n2, myFunctions->operations[0](n1, n2));
                break;
            case '-':
                printf("results of %d %c %d = %d\n", n1, 
                    sym, n2, myFunctions->operations[1](n1,n2));
                break;    
            case 'x':
                printf("results of %d %c %d = %d\n", n1, 
                    sym, n2, myFunctions->operations[2](n1,n2));
                break;       
            default:
                    printf("operation not defined!\n");
        }

    }

    free(myFunctions);
    return 0;
}

