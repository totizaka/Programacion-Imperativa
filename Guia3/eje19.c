#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

int num, cincos=0;

num=getint("\ningresar numero positivo");

for (; num > 0 ; num/=10 )
{
    if ((num%5)==0 && (num%10)!=0)
    {
        cincos++;
    }
    
}

printf("cantidad de cincos %d",cincos);


    return 0;
}