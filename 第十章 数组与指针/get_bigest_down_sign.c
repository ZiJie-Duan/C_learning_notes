#include <stdio.h>

int get_bigest_down_sign(double arr[], int length);

int main(void){
    
    double arr[5] = {2.1, 3.2, 1.1, 6.5, 5.4};

    printf("max index is %d",get_bigest_down_sign(arr,5));
    getchar();

}

int get_bigest_down_sign(double arr[], int length){

    double max_value = 0.0;
    int max_index = 0;
    for (int i=0; i<length; i++){
        if (arr[i] > max_value){
            max_value = arr[i];
            max_index = i;
        }
    }

    return max_index;
}
