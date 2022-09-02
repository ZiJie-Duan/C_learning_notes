#include <stdio.h>

int main(void){

    long double cash = 1000000.0;

    while(1){
        cash = cash * (long double)(1+0.08);
        cash -= 100000.0;
        __mingw_printf("\n%Lf",cash);
        if (cash <=0){
            break;
        }
    }
    getchar();
}