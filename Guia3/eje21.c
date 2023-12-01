#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

    int num = getint("ingrese numero");

    int numInvertido=0, primerNum, numRespaldo;

    numRespaldo=num;
    
    for (; num > 0 ; num/=10)
    {
        primerNum = (num % 10);
        numInvertido += primerNum;
        numInvertido*=10;
    }

numInvertido/=10;

if (numRespaldo==numInvertido)
{
    printf("numero %d es capicua\n",numRespaldo);
}
    return 0;
}
// 234 -> 23