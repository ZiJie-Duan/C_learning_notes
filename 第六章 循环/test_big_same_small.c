#include <stdio.h>


int main(void){;

    char input;
    printf("please input \"C\":");
    scanf("%c",&input);

    if (input == 'c'){
        printf("C = c");
    } else {
        printf("C != c");
    }

    getchar();
    getchar();

    //结论，C语言区分大小写字符串

}