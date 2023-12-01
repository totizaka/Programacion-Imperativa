#include <stdio.h>
#include <math.h>
#include "../Biblioteca/getnum.h"

double funcion(double x){

    return (cos(x));
}

int main(){

double extremoMenor=-8, exremoMayor=8, numero;
int sigAnterior=1, sigActual=1;

numero=extremoMenor;

if (funcion(numero)<0)
{
    sigAnterior=-1;
    sigActual=-1;
}
for (; numero <= exremoMayor; numero+=0.001)
{
    if (funcion(numero)<0)
    {
        sigActual=-1;
    }
    else{    
        sigActual=1;
    }
    if (sigActual!=sigAnterior)
    {
        printf("%f es raiz",numero);
    }
    sigAnterior=sigActual;
}

    return 0;
}