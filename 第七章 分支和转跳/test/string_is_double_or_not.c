#include <stdio.h>

int main(void){

    char str = "a"; //双引号是 字符串的定义
    //所以此处报错
    printf("%c",str);
    
    getchar();
}