#include <stdio.h>

int main(void){

    char name[20];
    char letter;

    while (1){

        for(int index =0; index <20; index++){
            printf("[read]\n");
            // 此处，scanf啥都吃！！！
            scanf("%c",&letter);
            if(letter == '\n'){
                break;
            }
            name[index] = letter;
        }
        printf("FINISH\n\nOut Put: ");
        
        for(int index =0; index <20; index++){
            printf("%c",name[index]);
        }
    }
}