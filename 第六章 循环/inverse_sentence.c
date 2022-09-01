#include <stdio.h>

int main(void){

    char sentence[255];
    char letter;
    int index =0;

    printf("please input a sentence>> ");
    
    while(index <255){
        scanf("%c",&letter);
        if (letter == '\n'){
            break;
        }
        sentence[index] = letter;
        index++;
    }

    for (index -=1; index >=0; index--){
        printf("%c",sentence[index]);
    }
    getchar();
    getchar();
}