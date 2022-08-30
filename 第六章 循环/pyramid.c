#include <stdio.h>

int main(void){
    char letter;
    int difference;

    printf("Please input a capital letter >>");
    scanf("%c",&letter);

    difference = letter - 65;
    printf("%d\n",difference);

    for (int index=0; index <= difference; index++){
        printf("\n");
        for (int spi=0; spi < difference-index; spi++){
            printf(" ");
        }
        for (int upi=0; upi < index; upi++){
            printf("%c",65+upi);
        }
        printf("%c",65+index);
        for (int downi=0; downi < index; downi++){
            printf("%c",65+index -1 -downi);
        }
        for (int spi=0; spi < difference-index; spi++){
            printf(" ");
        }
    }
    getchar();
    getchar();
}