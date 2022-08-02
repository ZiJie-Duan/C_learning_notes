#include <stdio.h>

int main(void){
    //此程序 用于测试数组的位数和数组index的关系
    //结论 编译器完全不care这个
    //需要保证 list 的 index 范围 是程序设计的调用范围
    int number_list[10];
    int cont;
    for(cont = 0;cont<=30;cont++){ 
        number_list[cont] = cont + 1;
    }
    printf("\nFINISH to RECORD");
    
    for(cont = 0;cont<=30;cont++){
        printf("\n%d",number_list[cont]);
    }
    printf("\nFINISH");
    getchar();
}
