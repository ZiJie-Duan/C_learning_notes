#include <stdio.h>

int get_bigest_value(int arr[], int lenght);
void get_order_list_bub(int arr[], int lenght);
void print_arr(int arr[],int lenght);

int main(void){
    int arr[5] = {10,23,234,33,2};
    printf("max = %d",get_bigest_value(arr,5));
    print_arr(arr,5);
    get_order_list_bub(arr,5);
    print_arr(arr,5);
    getchar();
}

int get_bigest_value(int arr[], int lenght){
    int max = 0;
    int tem = 0;
    for (int i=0; i<lenght; i++){
        if (tem = arr[i] > max) max = arr[i];
    }
    return max;
}

void get_order_list_bub(int arr[], int lenght){
    int tem = 0;
    for (int i=1; i<lenght; i++){
        for (int si=0; si <(lenght-i); si++){
            if (arr[si] > arr[si+1]){
                tem = arr[si];
                arr[si] = arr[si+1];
                arr[si+1] = tem;
            }
            print_arr(arr,5);
        }
    }
}

void print_arr(int arr[],int lenght){
    printf("\n[");
    for (int i=0; i <(lenght-1); i++){
        printf("%d, ",arr[i]);
    }
    printf("%d]",arr[lenght-1]);
}