#include <stdio.h>
#define A 321321321
#define B 312.32325
int main(void){
    printf("*%d*\n",A);
    printf("*%10d*\n",A);
    printf("%f\n",B);
    printf("%2.2f\n",B);
    printf("%3.2f\n",B);
    printf("%4.3f\n",B);
    getchar();
}