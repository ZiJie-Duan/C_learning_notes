#include <stdio.h>

int main(void){

    int number;
    long double result;

    do{
        printf("\nplease input a number: ");
        scanf("%d",&number);

        result = 1.0 / number;

        printf("\nresult: %Lf\n",result);

    }while(number > 0);

}