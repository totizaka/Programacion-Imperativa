#include <stdio.h>
#include "../Biblioteca/getnum.h"
#include "../Biblioteca/random.h"

float potencia(double base, int exponente){

int exponentepos=exponente, potencia=1;

if (exponente<0)
{
    exponentepos=exponente*(-1);
}

for (int i = 1; i <= exponentepos; i++)
{
    potencia*=base;
}
if (exponente>=0)
{
    return potencia;
}
else
{
    return (1/(float)potencia);
}    
}




int main(){

float num=potencia(0,4);

printf("%f",num);


    return 0;
}