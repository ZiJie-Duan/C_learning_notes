#include <stdio.h>

int main(void){

    int schar;
  
    int cont = 0;

    while ((schar = getchar()) != EOF){
        cont ++;
    }

    printf("%d",cont);

}