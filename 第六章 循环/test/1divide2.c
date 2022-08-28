#include <stdio.h>

int main(void){

    int number;
    long double result;

    do{
        printf("\nplease input a number: ");
        scanf("%d",&number);

        result = (long double)1 / (long double)number;

        __mingw_printf("\nresult: %Lg\n",result);
        //这个函数用于在Windows环境下输出 long double 类型的数据

    }while(number > 0);

}