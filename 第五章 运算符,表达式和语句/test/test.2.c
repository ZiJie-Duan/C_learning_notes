#include <stdio.h>

int main(void){
    int num = 1;
    while (++num<5){
        printf("num = %d\n",num);
    }
    num = 1;
    while (num++<5){
        printf("num = %d\n",num);
    }
    getchar();
}