#include <stdio.h>

int
Mayor (int a, int b, int c)
{
   return (a >= b && a >= c ? a : b >= a && b >= c ? b : c);

}

int main(){

int num1=30, num2=20, num3=40, mayor;

mayor=Mayor(num1,num2,num3);

printf("%d",mayor);

    return 0;
}