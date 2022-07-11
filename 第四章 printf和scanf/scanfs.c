#include <stdio.h>

int main(void){
    
    char name[30];
    char name2[30];

    printf(">>");
    scanf("%s",name);
    scanf("%s",name2);
    printf("\n1:%s\n",name);
    printf("\n2:%s\n",name2);
    getchar();
    // scanf function use "space" to split input data.

}