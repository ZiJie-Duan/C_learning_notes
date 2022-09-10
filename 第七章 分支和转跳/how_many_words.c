//编写一个程序读取输入，读到#字符停止
//然后报告读取的空格数、换行符数和所有其他字符的数量。
#include <stdio.h>

int main(void){
    
    int space = 0;
    int change_line = 0;
    int other_char = 0;
    char sc;

    while ((sc = getchar()) != '#'){
        //注意此处运算顺序！！
        
        switch (sc)
        {
        case ' ':
            space++;
            break;

        case '\n':
            change_line++;
            break;

        default:
            other_char++;
            break;
        }

    }

    printf("\n\nthe number of space is %d",space);
    printf("\nthe number of change_line is %d",change_line);
    printf("\nthe number of other_char is %d",other_char);
    printf("\nProgram exit!");
    getchar();
    getchar();
}