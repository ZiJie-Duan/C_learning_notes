#include <stdio.h>

int main(void){
    printf("this is calculate index funcition");
    double num = 2;
    int js = 1; 
    while (js < 30){
        num = num * 2;
        js = js + 1;
        printf("num : %10.2E\n",num);
    }
    getchar();
}