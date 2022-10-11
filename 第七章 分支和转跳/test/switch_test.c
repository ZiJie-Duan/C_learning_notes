
#include <stdio.h>

int main(void){

    int uinput;

    scanf("%d",&uinput);

    switch (uinput)
    {
    case 6/* constant-expression */:
        /* code */
        printf("%d",1);
        break;
    case 7/* constant-expression */:
        /* code */
        printf("%d",2);
        break;
    case 8/* constant-expression */:
        /* code */
        printf("%d",3);
        break;

    default:
        printf("%d",4);
        break;
    }

}