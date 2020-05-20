#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
size_t getstr( char **str, FILE *input ) {
    size_t chars_to_read = 0; ///BLOCK SIZE;
    size_t length = 0;
    /// ...snipped... see template file
    size_t chars = 0;
    while( ( chars = fread( *str + length, 1, chars_to_read, input ) ) ) {
    // you fill this out
    }
    // ...snipped... see template file
    return length;
}
*/
char encrypt( char str, size_t length ) {


    if (length <= 2){
        printf("hello");
    };
}


int main()
{

    char str[] = "ok";
    size_t length = strlen(str);
    encrypt(str, length);



    return 0;
}
