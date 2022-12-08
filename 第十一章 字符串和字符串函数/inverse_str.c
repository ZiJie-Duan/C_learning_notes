#include <stdio.h>

void inverse(char * str);
char * input(void);

int main(void){

    char * sentence = input();
    printf("%s\n",sentence);
    inverse(sentence);
    printf("%s\n",sentence);
}

void inverse(char * str){
    char * front = str;
    char * back = str;
    char temp;
    while (*back !='\0') back++;
    back--;
    while ((back-front) >0){
        temp = *back;
        *back = *front;
        *front = temp;
        front++; back--;
    }
}

char * input(void){
    static char sentence[500];
    char *p = sentence;
    while ((*p =getchar()) !='\n'){
        p++;
    }
    *p = '\0'; // *p not p, miss a '*' [bug]
    return sentence;
}