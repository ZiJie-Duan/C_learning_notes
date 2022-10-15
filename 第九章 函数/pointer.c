#include <stdio.h>

int invers_value(int * v1,int * v2);

int main(void){
    
    int v1 = 10;
    int v2 = 20;

    printf("\nv1 = %d, v2 = %d",v1,v2);
    invers_value(&v1,&v2);
    printf("\nv1 = %d, v2 = %d",v1,v2);
    getchar();

}

int invers_value(int * v1,int * v2){

    printf("\nGET v1 in %p, v2 in %p",v1,v2);
    int tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}
