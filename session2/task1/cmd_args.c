#include <stdio.h>
#include <stdlib.h>

int main( void ) {

    char buffer[100] = "The quick brown fox jumped over the lazy dog";

    char **argv; // dynamic array of char*
    int argc;

    // 1. first pass - count argc
    // don't assign argv just locate space ' ' and count tokens

    char *p;
    argc = 1;

    for(p=buffer; *p!='\0'; p++){
        if(*p == ' ')
            argc++;
    }

    // 2. dynamically allocate argv array
     argv = malloc( argc*sizeof(char *) );

    // 3. second pass - allocate and fill argv
    argv[0] = buffer;
    argc = 1;

    for(p=buffer; *p!='\0'; p++){
        if(*p == ' '){
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

    

    // free argv dynamic memory

    return 0;
}