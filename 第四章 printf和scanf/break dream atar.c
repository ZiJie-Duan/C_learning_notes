#include <stdio.h>

int main(void){
    char name[40];
    float atar;

    printf("This is a dream creator!!!\n");
    printf("please input your name:");
    scanf("%s",name);

    printf("\nwhat ATAR do you like? :");
    scanf("%f",&atar);
    
    printf("\nOH~~ my baby %s",name);
    if (atar > 95){
        printf("\n\n    Dream your fucking daily dream!!!");
    } else if (atar > 90) {
        printf("\n\n    OHHHH no nononon you don't have ability!");
    } else if (atar > 80) {
        printf("\n\n    oh your ATAR maybe is 50...");
        printf("\n    that means you can apply melbourne via the identity of abriginal people");
    } else if (atar > 60) {
        printf("\n\n   loser");
    } else if (atar > 40) {
        printf("\n\n   good you are a good people, you will get good mark!");
    }
    printf("\n\nFINISH");
    getchar();
    getchar();
}
