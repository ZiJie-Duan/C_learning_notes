#include <stdio.h>
#include <string.h>

int main(void){
    char word[40];
    printf("please input a word: ");

    scanf("%s",word);
    for (int index=strlen(word)-1; index >= 0; index--){
        printf("%c",word[index]);
    }
    getchar();
    getchar();

}