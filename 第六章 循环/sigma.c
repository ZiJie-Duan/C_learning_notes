#include <stdio.h>

int main(void){

    int number;
    long double result_add;
    long double result_les;
    long double result;

    do{
        printf("Please input a number:");
        scanf("%d",&number);

        result_add = 0; //此处将result归零
        for(int cont=1; cont <= number; cont++){
            result_add = result_add + (long double)1 / (long double)cont;
            //如果 result 是没有赋值的状态时，result直接相加会出错
        }

        result_les = 1; //此处将result归零
        for(int cont=2; cont <= number; cont++){
            result_les = result_les - (long double)1 / (long double)cont;
            //如果 result 是没有赋值的状态时，result直接相加会出错
        }

        result = result_add + result_les;

        __mingw_printf("\result_add: %Lf\n", result_add);
        __mingw_printf("\result_les: %Lf\n", result_les);
        __mingw_printf("\nresult: %Lf\n", result);

    } while (number >= 1);
}
