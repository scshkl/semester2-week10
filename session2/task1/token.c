
#include <stdio.h>
#include <string.h>

int main( void ) {

    char buffer[100] = "the quick brown fox jumped over the lazy dog";   // define a string to process

    // call strtok() repeatedly to tokenise the string on whitespace " "
    // print out each token

    char *p = strtok(buffer," ");     // call strtok()
    while( p != NULL ) {              // consume the string until empty (p=NULL)
        printf("%s\n",p);                 // output current token
        p = strtok(NULL," ");             // call strtok() on remaining part of string
    }
    
    return 0;
}