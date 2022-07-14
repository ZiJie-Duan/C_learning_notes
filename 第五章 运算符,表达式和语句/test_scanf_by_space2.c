#include <stdio.h>
int main (void)
{
 int a, b;
 printf ("请输入一个整数");
 scanf ("%d", &a);
 printf ("再输入一个整数");
 scanf ("%d", &b);
 printf ("a = %d b = %d\n", a, b);
 getchar();
 getchar();
return 0;
}