#include <stdio.h>
#include "../Getnum/getnum.h"
#include <math.h>

esPrimo(int num){

int i;

if(num<0)
{
    num=num*(-1);
}
if(num%2==0 || num<2)
{
    return 0;
}

for ( i = 2; i<sqrt(num) ; i++)
{
    if(num%i==0)
    {
        return 0;
    }
}
return 1;
}

int main(){

if (esPrimo(13))
{
    printf("es primo");
}


    return 0;
}