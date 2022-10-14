#include <stdio.h>

int main(void){

    int schar;

    while ((schar = getchar()) != EOF){
        printf("%c",schar);
    }


}