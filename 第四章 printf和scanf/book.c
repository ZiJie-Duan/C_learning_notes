#include <stdio.h>
#define BOOK "war and peace"

int main(void){
    float cost = 12.99;
    float percent = 80.0;
    printf("this copy of \"%s\" sells for \
$%2.2f\nthat is %2.0f%%",BOOK,cost,percent);
    getchar();
}

