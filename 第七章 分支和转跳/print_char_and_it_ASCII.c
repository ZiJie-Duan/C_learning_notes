#include <stdio.h>

int main(void){

    char ch;

    for (int cont; ch !="#"; cont++){
        scanf("%c",&ch);

        if ((cont%8) == 0){
            printf("\n%2c=%-4d",ch,ch);
        }else{
            printf("%2c=%-4d",ch,ch);
        }

    }

    getchar();
    getchar();


}