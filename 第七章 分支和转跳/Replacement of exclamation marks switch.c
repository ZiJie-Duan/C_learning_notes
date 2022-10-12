#include <stdio.h>

int main(void){
    
    int tanhao = 0;
    int double_tanhao = 0;
    char schar;

    printf("start\n");
    while(1){
        scanf("%c",&schar);

        if (schar == '#') break;

        switch (schar)
        {
        
        case '.':
            printf("!");
            tanhao += 1;
            break;
        
        case '!':
            printf("!!");
            double_tanhao += 1;
            break;
        
        default:
            printf("%c",schar);
            break;
        }
    }
    printf("!=%d !!=%d",tanhao,double_tanhao);
    getchar();
    getchar();

}