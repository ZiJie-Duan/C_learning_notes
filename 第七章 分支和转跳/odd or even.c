#include <stdio.h>

int main(void){

    int number;
    int number_odd = 0;
    int number_even = 0;
    int number_odd_total = 0;
    int number_even_total = 0;

    while(1){
        scanf("%d",&number);

        if (number == 0) break;

        if ((number%2) != 0){
            number_odd++;
            number_odd_total = number_odd_total + number;
        }else{
            number_even++;
            number_even_total = number_even_total + number;
        }

    }

    printf("number of odd is %d, average is %lf\n",\
    number_odd, (double)(number_odd_total/number_odd));
    printf("number of even is %d, average is %lf\n",\
    number_even, (double)(number_even_total/number_even));
    getchar();
    getchar();

}