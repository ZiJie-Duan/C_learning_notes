#include <stdio.h>

int main(void){

    double user[8];
    double accu[8];

    for(int index =0; index <8; index++){
        printf("\nplease in put the %d number>>",index+1);
        scanf("%lf",&user[index]);
        if(index == 0){
            accu[index] = user[index];
        }else{
            accu[index] = accu[index-1] + user[index];
        }
    }

    printf("\n\n");

    for(int index =0; index <8; index++){
        printf("%-6.2lf",user[index]);
    }
    printf("\n");
    for(int index =0; index <8; index++){
        printf("%-6.2lf",accu[index]);
    }

    getchar();
    getchar();

}

