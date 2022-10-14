#include <stdio.h>

int is_a_letter(char letter);

int main(void){

    int schar;

    int number_of_word = 0;
    int total_number_of_char = 0;
    int break_sign = 0;
    int last_char_is_letter = 0;

    while ((schar = getchar()) != EOF){
        if (is_a_letter(schar)){
            last_char_is_letter = 1;
            printf("%c",schar);
            total_number_of_char++;
        } else {
            if (last_char_is_letter == 1){
                printf("\n");
                last_char_is_letter = 0;
                number_of_word++;
            } else {
                continue;
            }
        }
    }
    number_of_word++;

    printf("\nthis File have %d words, avrage letter is %f",\
     total_number_of_char, ((float)total_number_of_char/(float)number_of_word));
    getchar();
}

int is_a_letter(char letter){
    if ((letter >= 65 && letter <= 90)\
    || (letter >= 97 && letter <= 122)) return 1;
    return 0;
}