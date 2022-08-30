#include <stdio.h>

int main(void){

    char letters[26];

    int index;
    int letters_index;

    for (index = 0,letters_index=97; index < 26; index++,letters_index++){
        letters[index] = letters_index;
    }
    for (index = 0; index < 26; index++){
        printf("\n%d \"%c\"",index+1,letters[index]);
    }
    getchar();
}