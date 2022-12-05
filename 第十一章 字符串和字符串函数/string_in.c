#include <stdio.h>

char * string_in(char *str1, char *str2);
void get_user_input(char *str);

int main(void){

    char string[500];
    char word[100];
    printf("please input a sentence >>");
    get_user_input(string);
    printf("please input a word >>");
    get_user_input(word);

    char *location;
    if (location = string_in(string,word)){
        printf("SUCCESS location ->%s",location);
    }else{
        printf("NOT IN IT");
    }

}

void get_user_input(char *str){
    while ((*str =getchar()) != '\n'){
        str++;
    }
    *str = '\0';
}

char * string_in(char *str1, char *str2){
    int state = 0;
    char * start_point;
    char * st1 = str1;
    char * st2 = str2;

    while(*st1 != '\0'){
        if (*st1 == *st2){
            if (state == 0) {start_point =st1; state =1;};
            st2++;
        } else {
            if (*st2 == '\0'){
                break;
            }
            if (state == 1) {start_point =NULL; state =0;};
            st2 = str2;
        }
        st1++;
    }
    return start_point;
}

