#include <stdio.h>

int is_a_letter(char letter);

int main(void){

    int schar;
    int last_char_is_letter = 0;

    while ((schar = getchar()) != EOF){

        if (last_char_is_letter == 0){
            if (is_a_letter(schar)){
                printf("%c \n",schar);
                last_char_is_letter = 1;
            }else{
                continue;
            }
        } else {
            if (is_a_letter(schar)){
                continue;
            }else{
                last_char_is_letter = 0;
            }
        }
    }
}

int is_a_letter(char letter){
    if ((letter >= 65 && letter <= 90)\
    || (letter >= 97 && letter <= 122)) return 1;
    return 0;
}