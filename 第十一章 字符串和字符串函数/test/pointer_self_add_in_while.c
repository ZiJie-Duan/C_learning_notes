#include <stdio.h>


int main(void){
    char str[] = "hello this is a test";
    char *p = str;
    while (*(++p) != '\0') continue;
    printf("->%c",*p);

}