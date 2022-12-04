#include <stdio.h>
#include <stdlib.h>

int get_n();
char * getnchar(int number);

int main(void){
    int number = get_n();
    printf("\nthis program gets %d char form user",number);
    printf("\n>>");
    char *p;
    p = getnchar(number);
    printf("\n\n->%s",p);
    free(p);
    printf("<-\n\n");
    system("pause");
}

int get_n(){
    int number = 0;
    char tmp;
    printf("please type a int value here >>");
    while((tmp = getchar()) != '\n'){
        if ((tmp>='0')&&(tmp<='9')){
            number = number*10 + tmp - '0';
        }
        continue;
    }
    return number;
}

char * getnchar(int number){
    static char *tmp;
    tmp = (char*)malloc((number+1) * sizeof(char));
    for (int i=0; i < number; i++){
        tmp[i] = getchar();
    }
    return tmp;
}