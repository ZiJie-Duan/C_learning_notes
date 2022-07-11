#include <stdio.h>

int main(void){
    float small_water = 3E-23;
    short kuatuo = 950;

    int PT_i;
    long long number;
    long long aaa;
    printf("this program can transfer PT to small_water\n");
    printf("PT:");
    scanf("%d",&PT_i);
    number = PT_i * kuatuo;
    printf("\n:%lld",number);
    aaa = number/small_water;
    printf("\nsmall whater is :%lld",aaa);

    getchar();
    getchar();

}