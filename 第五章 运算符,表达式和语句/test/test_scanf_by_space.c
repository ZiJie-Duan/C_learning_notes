#include <stdio.h>

int main(void){
    short a=0;
    short b=0;
    short c=0;
    short d=0;

    printf(">>");
    scanf("%d", &a);
    printf("%d >>",a);
    scanf("%d", &b);
    printf("%d >>",b);
    scanf("%d", &c);
    printf("%d >>",c);
    scanf("%d", &d);

    printf("FINISH INPUT");
    printf("\"%d\" \"%d\" \"%d\" \"%d\"",a,b,c,d);
    getchar();
    getchar();

}