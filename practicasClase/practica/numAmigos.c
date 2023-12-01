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
}

int numAmigos(int num1, int num2){

if (num1 < 0)
{
    num1=num1*(-1);
}
if (num2<0)
{
    num2=num2*(-1);
}

int i, val1=0, val2=0, sum1=0, sum2=0;

for ( i = 2; i <= num1 ; i++)
{
    if(num1%i==0)
    {
        val1=(num1/i);
        sum1+=val1;
    }
}

for ( i = 2; i <= num2 ; i++)
{
    if(num2%i==0)
    {
        val2=(num2/i);
        sum2+=val2;
    }
}

if (sum1==num2 && sum2==num1)
{
    return 1;
}
return 0;

}

int main(){

if(numAmigos(1184, 1210))
{
    printf("son amigos");
}
    return 0;
}


