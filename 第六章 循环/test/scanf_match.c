#include <stdio.h>

int main(void){
    char letter;
    char test = 'a'; //单引号！！是字符！！

    printf(">>");
    scanf("%c",&letter);
    printf("\nletter = %c",letter);
    printf("\ntest = %d",test);
    if (letter == test){
        printf("\nYES!");
    }else{
        printf("\nNOT match!");
    }
    getchar();
    getchar();
}