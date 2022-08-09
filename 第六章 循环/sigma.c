#include <stdio.h>

int main(void){

    int number;
    long double result;

    do{
        printf("\nplease input a number: ");
        scanf("%d",&number);

        result = 0;
        for(int cont=1; cont <= number; cont++){
            result += 1 / cont;
        }

        printf("\nresult: %Lf\n",result);

    }while(number > 0 || );

}