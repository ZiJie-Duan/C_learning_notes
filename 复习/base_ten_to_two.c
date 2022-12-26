#include <stdio.h>

int base_ten_two(int value);

int main(void){
    printf("%d",base_ten_two(202));
}

int base_ten_two(int value){
    if (value<=1){
        return value;
    } else {
        return (base_ten_two((int)(value/2))*10) +value%2;
    }
}