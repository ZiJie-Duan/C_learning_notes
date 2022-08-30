#include <stdio.h>

int main(void){
    for (int index = 1; index < 6; index++){
        for (int index_2 = 1; index_2 <= index; index_2++){
            printf("$");
        }
        printf("\n");
    }
    getchar();
}