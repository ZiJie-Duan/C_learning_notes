#include <stdio.h>
#include <stdlib.h>

int main(void){

    char word[300];
    char *p = word;
    char temp;
    int max_value;
    int cont = 1;

    printf("\nplease input a number >>");
    scanf("%d",&max_value);

    printf("\ntype a word >>");
    while(((temp =getchar()) =='\n')||(temp =='\t')||(temp ==' ')){
        continue;
    }
    *p = temp;
    while(((temp =getchar()) !='\n')&&(temp !='\t')&&(temp !=' ')&&(cont++ <=max_value)){
        p++;
        *p = temp;
    }
    *(++p) = '\0';
    printf("\n\nword: ->%s<-\n",word);
    system("pause");
    getchar();
}