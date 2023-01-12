#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char * key;
    char * value;
}linked;

typedef linked (*linkt);

void add(char *key, char *value, linkt li);

int main(void){
    
    linkt lists = malloc(20* sizeof(linked));
    printf("\n%d\n",sizeof(linked));
    printf("\n%x and %x\n",&lists[0],&lists[1]);
    //struct linked lists[50];
    //li.key = "hello";
    //li.value = "yes";
    char ok[] = "hello";
    char okey[] = "helsdlo";
    add(ok,okey,lists);
    printf("%s:%s",lists[0].key,lists[0].value);
    printf("\n%s:%s",lists[10].key,lists[10].value);
    getchar();
}


void add(char *key, char *value, linkt li){
    li[0].key = key;
    li[0].value = value;
    li[10].key = key;
    li[10].value = value;
}