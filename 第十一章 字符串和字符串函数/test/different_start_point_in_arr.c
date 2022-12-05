#include <stdio.h>

void print_three(char *p);

int main(void){

    char name[] = "Peter Duan";

    print_three(name+2);

}

void print_three(char *p){
    for(int i=0; i<3; i++){
        printf("\n->%c",p[i]);
    }
}