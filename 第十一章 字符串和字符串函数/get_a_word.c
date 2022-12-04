#include <stdio.h>
#include <stdlib.h>

int main(void){

    char word[300];
    char *p = word;
    char temp;
    printf("\ntype a word >>");
    while(((temp =getchar()) =='\n')||(temp =='\t')||(temp ==' ')){
        continue;
    }
    *p = temp;
    while(((temp =getchar()) !='\n')&&(temp !='\t')&&(temp !=' ')){
        p++;
        *p = temp;
    }
    *(++p) = '\0';
    printf("\n\nword: ->%s<-\n",word);
    system("pause");
}