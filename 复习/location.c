#include <stdio.h>

void write(int n)
{   
    printf("\n");
    int l = sizeof(n)*8;//总位数。
    int i;
    if(i == 0)
    {
         printf("0");
         return;
     }
    for(i = l-1; i >= 0; i --)//略去高位0.
    {
        if(n&(1<<i)) break;
    }
 
    for(;i>=0; i --)
        printf("%d", (n&(1<<i)) != 0);
}

void oled_write_data(int data){
  int data1 = data&0b11110000;
  data1 = data>>4;
  int data2 = data&0b00001111;
  data1 = (data1*16)|0b00001000;
  data2 = (data2*16)|0b00001000;
  write(data1);
  write(data1|0b00000100);
  write(data2);
  write(data2|0b00000100);
}
int main(void){

    int data = 0b10000000;
    oled_write_data(data);

    getchar();

}