#include <stdio.h>

int main(void){
    double number1, number2;
    double df, ti;
    int status;

    while (1){
        printf("\nPlease input number1 (q to quit): ");
        if (scanf("%lf",&number1)==0){
            break;
        }
        printf("\nPlease input number2: ");
        scanf("%lf",&number2);
        df = number1 - number2;
        ti = number1 * number2;
        printf("\nresult: %lf\n",(double)(df/ti));
    }
}