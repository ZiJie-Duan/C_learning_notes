#include <stdio.h>

int main(void){
    int arr[2][3] = {{1,2,3},{4,5,6}};
    printf("arr = %p arr[0] = %p", arr,arr[0]);
    printf("\narr + 1 = %p arr[1] = %p", arr + 1, arr[1]);
    printf("\n*arr[0] = %d  arr[0][0] = %d", *arr[0], arr[0][0]);
    getchar();
}