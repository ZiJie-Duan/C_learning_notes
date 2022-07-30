#include <stdio.h>

int main(void){
    char number;
    int status;

    printf("please input a str>>");
    status = scanf("%c",&number);
    printf("status: %d",status);
    getchar();
    getchar();
    //结论就是
    //scanf输入模式为%d的时候，输入字符
    //返回值为 0，提示出错，但！！
    //设置为 %c 输入数字 却依旧是 1
    //就离谱，鬼md

}