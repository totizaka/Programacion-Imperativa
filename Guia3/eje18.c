#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

int num, cantidad, factorial=1;

do
{
    num=getint("ingrese numero mayor o igual a 0");
} while (num<0);

if(num!=0)
{
    for (cantidad = 1; cantidad <= num; cantidad++)
    {
        factorial*=cantidad;
    }
}
else
{
        factorial=0;
}
printf("el factroial es %d",factorial);

return 0;
}