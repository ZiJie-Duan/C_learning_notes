#include <stdio.h>

int main(void){

    int list1[5] = {1,2,3,4,5};
    int *p = list1;

    printf("\n&list1 = %p",&list1);
    printf("\n&list1[0] = %p",&list1[0]);
    printf("\n&p = %p",&p);
    printf("\nlist1[0] = %d",list1[0]);
    printf("\n*p = %d",*p);
    
    int list2[2][2] = {{1,2},{3,4}};
    int **p2 = list2;

    printf("\nlist2[0][1] == %d",*((*p2)+1));
    //printf("list2[1][0] == %d",*(p2 + 1));
    getchar();
}

