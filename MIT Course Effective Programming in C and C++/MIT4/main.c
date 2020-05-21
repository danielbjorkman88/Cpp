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


void splitString2(char str[], char *start[], char *end, int length1, int length2) {
  strncpy(start, str , length1 );
  ///start[length/2 ] = '\0';
  strncpy(end, str + length1 , length2 +1);

}
char* reverse( char str[], char rev[], size_t length ) {
    int k = length-1;
    for(int j = 0; j < length; j++)
    {
        rev[j] = str[k];
        k--;
    }
    rev[length ] = '\0';
}

char* encrypt( char str[], size_t length ) {



    if (length <= 2){
        return str;
    };

    int length1;
    int length2;

    if (length%2){
        length1 = length/2;
        length2 = length/2 + 1;
    }
    else {
        length1 = length/2;
        length2 = length/2;
    }

    char *sub1 = (char*) malloc(length1);
    sub1[length/2 ] = '\0';
    char *sub2 = (char*) malloc(length2);


    char *rev1 = (char*) malloc(length1);
    char *rev2 = (char*) malloc(length2);

    splitString2(str,sub1, sub2, length1, length2);



    reverse(sub1, rev1, length1);
    reverse(sub2, rev2, length2);


    sub1 = encrypt(rev1, length1);
    sub2 = encrypt(rev2, length2);

    return strcat(sub1, sub2);;

}



int main()
{

  const char* str = "123456789";
  printf(str);
  printf("\n");
  size_t length = strlen(str);
  printf(encrypt(str, length));



  return 0;
}

    ///char str[] = "1234";
///    size_t length = strlen(str);
    ///printf(encrypt(str, length));
  /*

      char *rev = (char*) malloc(length);
    printf(str);
    printf("\n");
    reverse(str, rev, length);
    printf(rev);
    printf("\n");
      char *rev = (char*) malloc(length);
    int k = length-1;
    for(int j = 0; j < length; j++)
    {
        rev[j] = str[k];
        k--;
    }
    rev[length ] = '\0';

    printf(str);
    printf("\n");
    printf(rev);
    printf("\n");


  char *start = (char*) malloc(length/2);
  char *end = (char*) malloc(length/2 );
  int position = length/2;
  strncpy(start, str , length/2 +1);
  start[length/2 ] = '\0';
  strncpy(end, str + position , length/2 +1);
  printf(start);
  printf("\n");
  printf(end);
  printf("\n");

  splitString(str,length);
  printf("\n");
  printf("hello");
  printf("\n");

  char *sub1 = (char*) malloc(length/2);
  sub1[length/2 ] = '\0';
  char *sub2 = (char*) malloc(length/2);
  splitString2(str,sub1, sub2, length);
  printf(sub1);
  printf("\n");
  printf(sub2);
  void splitString(char str[], int length) {
  char *start = (char*) malloc(length/2);
  char *end = (char*) malloc(length/2 );
  int position = length/2;
  strncpy(start, str , length/2 +1);
  start[length/2 ] = '\0';
  strncpy(end, str + position , length/2 +1);
  printf(start);
  printf("\n");
  printf(end);

}
*/
