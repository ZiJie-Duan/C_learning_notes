#include <stdio.h>
#define DATA_GROUP 2
#define DATA_LENGHT 2

void get_user_input(int group, int lenght, double arr[group][lenght]);
void print_double_2_arr(int group, int lenght, double arr[group][lenght]);
void calculate_data_average(int group, int lenght, double arr[group][lenght]);


int main(void){

    double data[DATA_GROUP][DATA_LENGHT];
    get_user_input(DATA_GROUP,DATA_LENGHT,data);
    print_double_2_arr(DATA_GROUP,DATA_LENGHT,data);
    calculate_data_average(DATA_GROUP,DATA_LENGHT,data);
    getchar();
    getchar();
}

void calculate_data_average(int group, int lenght, double arr[group][lenght]){
    double total = 0;
    for (int i=0; i<group; i++){
        total = 0;
        for (int ii=0; ii<group; ii++){
            total += (double)arr[i][ii];
        }
        printf("\naverage[%d] = %f",group,(double)total/lenght);
    }
}

void get_user_input(int group, int lenght, double arr[group][lenght]){
    double tem;
    for (int i=0; i<group; i++){
        printf("\nPlease type in a group data. [%d]",i+1);
        printf("\n(num*%d)>>",(int)DATA_LENGHT);
        for (int ii=0; ii<lenght; ii++){
            scanf("%lf",&tem);
            arr[i][ii] = tem;
        }
    }
}

void print_double_2_arr(int group, int lenght, double arr[group][lenght]){
    printf("\n[");
    for (int i=0; i<group; i++){ 
        if (i==0) {printf("[");} else {printf(" [");};
        for (int i2=0; i2 <(lenght-1); i2++){
            printf("%f, ",arr[i][i2]);
        }
        printf("%f]",arr[i][lenght-1]);
        if (i!=group-1) printf("\n");
    }
    printf("]");
}