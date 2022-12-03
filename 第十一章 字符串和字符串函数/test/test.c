#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[] = "Peter Duan";
    char *p = name;
    int i = 0;
    while(*p){
        printf("%c", *p);
        p++;
        i++;
    }
    printf("\n\n%d", i);
    getchar();
}
