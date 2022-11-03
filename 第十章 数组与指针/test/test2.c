#include <stdio.h>

int main(void){
    int (*ptr)[2];
    int arr[2][2] = {{12},{14,16}};
    ptr = arr;
    printf("%d\n",**ptr);
    printf("%d\n",**(ptr+1));
    getchar();
}
