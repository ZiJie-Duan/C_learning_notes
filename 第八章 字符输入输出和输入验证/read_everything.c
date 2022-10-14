#include <stdio.h>

int main(void){

    int schar;

    while ((schar = getchar()) != EOF){

        if (schar >= 32 && schar <= 126){

            printf("\n%c : %d",schar,schar);

        } else if (schar == '\n') {

            printf("\n\\n : %d",schar);

        } else if (schar == '\t') {

            printf("\n\\t : %d",schar);

        } else {
            printf("\n[N] : %d",schar);
        }
    }
    getchar();
    getchar();
}