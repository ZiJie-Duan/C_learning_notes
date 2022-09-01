#include <stdio.h>

int main(void){
    int test[8];
    //此处生成的列表 一共有8位，并非是索引到8（有9位）
    for (int index =0; index <8; index++){
        test[index] = 6;
    }
    for (int index =0; index <8; index++){
        printf("%d",test[index]);
    }
    getchar();

}