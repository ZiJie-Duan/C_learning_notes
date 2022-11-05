#include <stdio.h>

void copy_ptr(double target[], double source[], int number);
void print_double_2_arr(int lenght, int type, double arr[lenght][type]);

int main(void){
    double arr[3][4] = {
        {1.1, 2.2, 3.3, 4.4},
        {5.5, 6.6, 7.7, 8.8},
        {9.9, 10.1, 11.2, 12.3}
    };
    print_double_2_arr(3,4,arr);
    double arr2[3][4];
    double (*p)[4] = arr;
    double (*pt)[4] = arr2;
    while (p != arr+3){
        copy_ptr(*pt,*p,4);
        pt++;
        p++;
    }
    print_double_2_arr(3,4,arr2);
    getchar();
}


void copy_ptr(double target[], double source[], int number){
    for (int i =0; i <number; i++){
        *(target + i) = *(source + i);
    }
}

void print_double_2_arr(int lenght, int type, double arr[lenght][type]){\
    printf("\n[");
    for (int i=0; i<lenght; i++){ 
        if (i==0) {printf("[");} else {printf(" [");};
        for (int i2=0; i2 <(type-1); i2++){
            printf("%f, ",arr[i][i2]);
        }
        printf("%f]",arr[i][type-1]);
        if (i!=lenght-1) printf("\n");
    }
    printf("]");
}