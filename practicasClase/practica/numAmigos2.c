#include <stdio.h>
#include <math.h>
#include "../Getnum/getnum.h"

int checkDivisoresEqualNum(int num)
{
if (num<0)
{
    num=num*(-1);
}
int val=0, sum=0;
for ( int i = 2; i <= num ; i++)
{
    if(num%i==0)
    {
        val=(num/i);
        sum+=val;
    }
}
return sum;
}

int numAmigos(int num1, int num2)
{
return (checkDivisoresEqualNum(num1)==num2 && checkDivisoresEqualNum(num2)==num1);
}

int main(){

if(numAmigos(1184, 1210))
{
    printf("son amigos");
}
else printf("no son amigos");
    return 0;
}