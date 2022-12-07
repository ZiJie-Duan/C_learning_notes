#include <stdio.h>

void remove_space(char * str);
void get_a_line(char * str);

int main(void){

    char sentence[500];
    while (1){
        printf("\n>>");
        get_a_line((char *)sentence);
        if (sentence[0] == '\0'){
            break;
        }
        remove_space((char *)sentence);
        printf("%s",sentence);
    }
}

void get_a_line(char * str){
    while ((*str =getchar()) !='\n'){
        str++;
    }
    *str = '\0';
}

void remove_space(char * str){
    char * new_str = str;
    while(*str!='\0'){
        if (*str!=' '){
            *new_str = *str;
            new_str++;
        }
        str++;
    }
    *new_str = '\0';
}