#include <stdio.h>

int main(void){
    int number = 10;
    int cont = 0;
    while(number != 0){
        number /= 10;
        cont++;
    }
    printf("%d",cont);
    getchar();
}