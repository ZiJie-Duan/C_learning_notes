#include <stdio.h>

int get_digit(long long value){
    int cont;
    for (cont=0 ; value != 0; cont++){
        value /= 10;
    }
    return cont;
}

int main(void){
    int up;
    int down;

    int format_number;
    int format_number_square;
    int format_number_cube;

    printf("please input lower limit: ");
    scanf("%d",&down);
    printf("\nplease input upper limit: ");
    scanf("%d",&up);
    printf("\n\n");

    format_number = get_digit((long long)up);
    format_number_square = get_digit((long long)(up*up));
    format_number_cube = get_digit((long long)(up*up*up));

    for (int cont = 0; cont < format_number + format_number_square\
    + format_number_cube + 10; cont++){
        printf("-");
    }

    for (int cont = down; cont <= up; cont++){
        printf("\n| %*lld | %*lld | %*lld |",\
        format_number,(long long)(cont),\
        format_number_square,(long long)(cont*cont),\
        format_number_cube,(long long)(cont*cont*cont));
    }
    // 注意！！！输出时，确保输入数据的类型匹配
    // 如果没有定义 记得使用显性转换

    printf("\n");
    for (int cont = 0; cont < format_number + format_number_square\
    + format_number_cube + 10; cont++){
        printf("-");
    }
    getchar();
    getchar();
}