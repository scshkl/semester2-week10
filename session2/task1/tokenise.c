#include <stdio.h>
#include <stdlib.h>

int main( void ) {

    char buffer[100] = "the quick brown fox jumped over the lazy dog";

    char *argv[10];  // argv is an array of 10 char* pointers
    int argc = 0;    // argc max is 10
    
    // iterate through each character of the string
    // every time you find a space ' ' assign a new token to argv[]
    char *p;

    argv[0] = buffer;
    argc = 1;

    for( p=buffer; *p!='\0'; p++ ) {    // for loop form
        if( *p == ' ' ) {
            *p = '\0';
            argv[argc] = p+1;
            argc++;
        }
    }

    // check output for argc,argv
    printf("argc = %d\n",argc);
    for( int k=0; k<argc; k++ ) {
        printf("argv[%d] = %s\n",k,argv[k]);
    }

    return 0;
}