#include <stdio.h>

int main(void){

    long double small_wang = 100.0;
    long double old_lee = 100.0;
    long double small_wang_constant_rate = 10.0;
    long double old_lee_rate = 0.05;

    for (int year =1; year <100; year++){
        small_wang += small_wang_constant_rate;
        old_lee = old_lee*(1 + old_lee_rate);
        printf("\nyear: %d",year);
        __mingw_printf("\nold_lee: %Lf",old_lee);
        __mingw_printf("\nsmall_wang: %Lf",small_wang);
        if (old_lee > small_wang){
            break;
        }
    }

    getchar();
    getchar();

}