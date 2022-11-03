#include <stdio.h>

int main(void){

    int a[5] = {1,2,3,4,5};
    printf("\n%x",a);
    printf("\n%x",&a);
    printf("\n%x",a+1);
    printf("\n%x",a+2);
    printf("\n%x",&a+1);
    printf("\n%x\n\n",&a+2);

    int *p = a;
    printf("\n%x",p);
    printf("\n%x",p+1);
    printf("\n%d",*(p+2));

    getchar();

}