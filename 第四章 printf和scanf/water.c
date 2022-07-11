#include <stdio.h>

int main(void){
    float quak = 3E-23;
    short n = 950;

    int number;
    int cal;
    double calcal;
    printf(">>");
    scanf("%d",&number);

    cal = n * number;
    calcal = cal / quak;
    printf("result: %f",calcal);

    getchar();
    getchar();
}