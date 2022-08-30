#include <stdio.h>

int main(void){

    char name1[30];
    char name2[] = "Peter Duan";
    printf("please input your name\n");
    scanf("%s",name1);
    printf("\nyour name %s ", name1);
    printf("\n\"%s\" the last two char is \"%c\" and \"%c\"",name2,name2[9],name2[10]);
    getchar();
    getchar();
}