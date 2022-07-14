#include <stdio.h>

int main(void){

    int size;
    printf("size >>");
    scanf("%d",&size);

    //第一行格式化输出
    printf(" * |");
    short cont = 0; 
    while (++cont <= size){
        printf("%5d",cont);
    }

    //中间横线
    short gang_size = 5 + (size*5);
    printf("\n");
    while (--gang_size > 0){
        printf("-");
    }

    //循环相乘 内容输出
    int cont_2 = 0;
    cont = 0;
    int result;

    while (++cont <= size){
        printf("\n%2d |",cont);
        cont_2 = 0;
        while (++cont_2 <= size){
            result = cont * cont_2;
            printf("%5d",result);
        }

    }
    printf("\n\nFINISH");
    getchar();
    getchar();

}