#include <stdio.h>
#include <windows.h>

int main(void){
    printf("I can print vioce...\n");
    Sleep(1000);
    printf("3\n");
    Sleep(1000);
    printf("2\n");
    Sleep(1000);
    printf("1\n");
    Sleep(1000);
    printf("0\n");
    printf("execute \"printf(\"\\a\");\" ");
    printf("\a");
    Sleep(3000);
} 