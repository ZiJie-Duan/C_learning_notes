#include <stdio.h>

void get_input(char *str);
void analyze(char *str, int * result);


int main(void){
    char string[500];
    int result[5];
    printf("\n>>");
    get_input(string);
    analyze(string,result);

    printf("\nword=%d,cap=%d,low=%d,symb=%d,num=%d",
    result[0],result[1],result[2],result[3],result[4]);
}

void get_input(char *str){
    while((*str=getchar()) !=EOF) str++;
    *str = '\0';
}

void analyze(char *str, int *result){
    int num_word = 0;
    int num_captal = 0;
    int num_lowp = 0;
    int num_symble = 0;
    int num_number = 0;

    int in_a_word = 0;
    
    while(*str != '\0'){

        if ((*str>=65) && (*str<=90)){ //captal
            num_captal++;
            if (in_a_word==0) in_a_word = 1;

        } else if ((*str>=97) && (*str<=122)){ //lowp
            num_lowp++;
            if (in_a_word==0) in_a_word = 1;

        } else if ((*str>=48) && (*str<=57)){ //numbers
            num_number++;
            if (in_a_word) {in_a_word =0; num_word++;}
        
        } else {
            num_symble++;
            if (in_a_word) {in_a_word =0; num_word++;}
        }
        str++;
    }
    result[0] = num_word;
    result[1] = num_captal;
    result[2] = num_lowp;
    result[3] = num_symble;
    result[4] = num_number;
}