#include <stdio.h>

double min(double value1, double value2);

int main(void){

    double a = 220.66;
    double b = 221.7789;

    printf("%lf",min(a,b));
    getchar();

}

double min(double value1, double value2){
    if (value1 > value2){
        return value2;
    } else {
        return value1;
    }
}