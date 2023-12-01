#include <stdio.h>
#include "../Getnum/getnum.h"
#include <math.h>

int esPrimo(int num){

int i;

if(num<0)
{
    num=num*(-1);
}
if(num<2)
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

int numerosprimos(){

int numero;

for (numero = 0; numero < 100; numero++)
{
    if (esPrimo(numero))
    {
        printf("%d ",numero);
    }
}
return 0;
}
int main(){

numerosprimos();

    return 0;
}