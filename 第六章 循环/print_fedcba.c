#include <stdio.h>
//70
int main(void){
    int cr = 70;
    for (int index = 1; index < 7; index++){
        for (int index_2 = 0; index_2 < index; index_2++){
            printf("%c",cr-index_2);
        }
        printf("\n");
    }
    getchar();   
}