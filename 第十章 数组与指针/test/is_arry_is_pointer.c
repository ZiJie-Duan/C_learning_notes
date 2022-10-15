#include <stdio.h>

void print_arry(int *arr, int size);

int main(void){

    int ar1[6] = {1,2,3,4,5,6};
    print_arry(ar1,6); //本质上数组名 就是数字首个元素的指针
    print_arry(&ar1[0],6); //直接传入 也可以
    getchar();

}

void print_arry(int *arr, int size){
    printf("\n[");
    for (int cont = 0; cont < size; cont++){
        printf("%d,",arr[cont]);
    }
    for (int cont = 0; cont < size; cont++){
        printf("%d,",*(arr + cont)); //自然也可以使用在指针上 加一的方式来实现
    }
    printf("]");

}