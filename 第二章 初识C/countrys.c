#include <stdio.h>

int main(void){
    void br(void);
    void ic(void);

    br();
    printf(", ");
    ic();
    printf("\n");
    br();
    printf("\n");
    ic();

}

void br(void){
    printf("Brazil, Russia");
}

void ic(void){
    printf("India, China");
}