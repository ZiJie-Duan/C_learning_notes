#include <stdio.h>

int main(void){
    
    int tanhao = 0;
    int double_tanhao = 0;
    char schar;

    printf("start\n");
    while(1){
        scanf("%c",&schar);

        if (schar == '#'){
            break;
        } else if (schar == '.'){
            printf("!");
            tanhao += 1;
        } else if (schar == '!'){
            printf("!!");
            double_tanhao += 1;
        } else {
            printf("%c",schar);
        }
    }
    printf("!=%d !!=%d",tanhao,double_tanhao);
    getchar();
    getchar();

}