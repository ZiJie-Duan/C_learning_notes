#include <stdio.h>


int main(void){
    int *ptr;
    int torf[2][2] = {{12},{14,16}};
    printf("%d\n",torf[0][0]);
    printf("%d\n",torf[0][1]);
    printf("%d\n",torf[1][0]);
    printf("%d\n",torf[1][1]);
    ptr = torf[0];
    printf("%d\n",*ptr);
    printf("%d\n",*(ptr+2));
    getchar();
}