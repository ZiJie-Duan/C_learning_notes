#include <stdio.h>

int main(void){
    double one_year = 3.156E7;
    short age;
    printf("This program is used to calculate how many seconds do you alive in the world.\n");
    printf("what is your age? :");
    scanf("%d",&age);
    long second = age * one_year;
    printf("\nNow you alive in the world at %ld",second);
    getchar();
    getchar();
}