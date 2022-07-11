#include <stdio.h>
#include <string.h>
int main(void){
    char first_name[30], second_name[30];
    printf("this program is used to print your name.\n");
    printf("what is your full name:");
    scanf("%s",first_name);
    scanf("%s",second_name);
    printf("\n%s %s",first_name,second_name);
    printf("\n%*d %*d",\
strlen(first_name),strlen(first_name),strlen(second_name),strlen(second_name));
    printf("\n\n%s %s",first_name,second_name);
    printf("\n%-*d %-*d",\
strlen(first_name),strlen(first_name),strlen(second_name),strlen(second_name));
    getchar();
    getchar();
}