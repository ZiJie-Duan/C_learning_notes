#include <stdio.h>

char * mystrncpy(char *s1, char *s2, int n);

int main(void){

    char str1[20];
    char str2[20] = "this is a test";
    printf("%s",mystrncpy(str1,str2,20));
}

char * mystrncpy(char *s1, char *s2, int n){
    int i;
    for (i=0; i <n; i++){
        s1[i] = s2[i];
        if (s2[i] == '\0'){
            return s1;
        }
    }
    return s1;
}