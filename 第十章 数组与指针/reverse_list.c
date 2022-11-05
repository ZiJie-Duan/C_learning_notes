#include <stdio.h>

void reverse_list(double arr[], int length);
void print_arr(double arr[],int lenght);

int main(void){
    double arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double arr2[8] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    print_arr(arr2,8);
    reverse_list(arr2,8);
    print_arr(arr2,8);
    getchar();

}

void reverse_list(double arr[], int length){
    double tem = 0;
    for (int i = 0; i<(int)(length/2); i++){
        tem = arr[i];
        arr[i] = arr[length-1-i];
        arr[length-1-i] = tem;
    }
}

void print_arr(double arr[],int lenght){
    printf("\n[");
    for (int i=0; i <(lenght-1); i++){
        printf("%f, ",arr[i]);
    }
    printf("%f]",arr[lenght-1]);
}