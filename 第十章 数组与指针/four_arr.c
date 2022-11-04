#include <stdio.h>

void copy_arr(double target[], double source[], int number);
void copy_ptr(double target[], double source[], int number);
void copy_ptrs(double target[], double source[], double *end_printer);
void print_arr(double arr[], int lenght);

int main(void){

    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    print_arr(target1,5);
    print_arr(target2,5);
    print_arr(target3,5);
    getchar();
}

void copy_arr(double target[], double source[], int number){
    for (int i =0; i <number; i++){
        target[i] = source[i];
    }
}

void copy_ptr(double target[], double source[], int number){
    for (int i =0; i <number; i++){
        *(target + i) = *(source + i);
    }
}

void copy_ptrs(double target[], double source[], double *end_printer){
    double *sp = source;
    double *tp = target;
    while (sp != end_printer){
        *tp = *sp;
        tp++;
        sp++;
    }
}

void print_arr(double arr[],int lenght){
    printf("\n[");
    for (int i=0; i <(lenght-1); i++){
        printf("%f, ",arr[i]);
    }
    printf("%f]",arr[lenght-1]);
}