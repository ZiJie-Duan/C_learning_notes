#include <stdio.h>

int main(void){

    int arrp[8] = {1,2,3,4,5,6,7,8};
    
    for (int cont = 7; cont >= 0; cont--){
        printf("%d",arrp[cont]);
    }
    getchar();
    getchar();
    
}