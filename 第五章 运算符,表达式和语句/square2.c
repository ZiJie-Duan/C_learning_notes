#include <stdio.h>

int main(void){

    int num = 1;
    while (num++ < 21){
        printf("num: %3d, %6d\n",num,num*num);
    }
    getchar();
    
}