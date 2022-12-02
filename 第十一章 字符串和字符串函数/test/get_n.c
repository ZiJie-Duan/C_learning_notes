#include <stdio.h>

char * getnchar(int number);

int main(void){
    printf("this program gets 10 char form user");
    printf("\n>>");
    input
}

char * getnchar(int number){
    static char tmp[number];
    for (int i=0; i < number; i++){
        tmp[i] = getchar();
    }
    return tmp;
}