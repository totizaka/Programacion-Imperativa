#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

int num, posicion, binario=0, bits=0;

do
{
    num=getint("ingresar numero positivo");
} while (num<0);

for (posicion = 1; num > 0; num/=2, posicion*=10 )
{
    if (num%2 != 0)
    {
        binario+=posicion;
        bits++;
    }
}

printf("cantidad de bits: %d",bits);




    return 0;
}