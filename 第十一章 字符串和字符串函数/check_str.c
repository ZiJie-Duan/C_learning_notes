#include <stdio.h>

int is_within(char sign, char *str);

int main(void){
    printf("\ninput char >>");
    char string[] = "hello jack";
    char tem;
    while ((tem=getchar()) != 'q')
    {   
        if (tem == '\n') continue;
        printf("\n%d",is_within(tem,string));
        printf("\ninput char >>");
    }
}

int is_within(char sign, char *str){
    while (*str != '\0'){
        if (sign == *str){
            return 1;
        }
        str++;
    }
    return 0;
}