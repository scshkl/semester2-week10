
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data definitions (part a.)
// Define an enumeration and typedef to `Type`
typedef enum _type{
    INTEGER,
    REAL,
    STRING
}Type;

// Define a union and typedef to `Value`
typedef union _value{
    int ival;
    float fval;
    char sval[10];
} Value;

// Define a struct, inckuding `Type` and `Value` and typedef to `Variable`
typedef struct _variable{
    Type t;
    Value v;
}Variable;

// Function prototypes (part b.)
 void print( Variable var ); 
// Variable assign( Type t, Value v );
// Variable add( Variable var1, Variable var2 );

int main( void ) {

    // define and initialise Variable, eg. 
    Variable var1 = { .t=INTEGER, .v.ival=2 };
    printf("var1.value:%d\n", var1.v.ival);
    print(var1);

    return 0;
}

void print(Variable var){
    switch(var.t){
        case INTEGER:
            printf("%d\n",var.v.ival);
            break;
        case REAL:
            printf("%f\n",var.v.fval);
            break;
        case STRING:
            printf("%s\n",var.v.sval);
            break;
        default:
            printf("Unknown type\n");
    }
}