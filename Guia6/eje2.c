#include <stdio.h>
#include <math.h>
#include "../Biblioteca/getnum.h"

int menu()
{
    int opciones=getint("\nElegir opcion:\n1: Simplificar una fraccion\n2: Sumar fracciones\n3: Terminar la ejecucion\n");

return opciones;
}

int DivComunMaximo(int num1, int num2){

    int divisor;

    divisor=(num1>num2 ? num1 : num2);

    for (; divisor >= 1; divisor--)
    {
        if (num1%divisor==0 && num2%divisor==0)
        {
            break;
        }
    }
    return divisor;
}

int simpFracciones(int num, int denom, int rtasimp[])
{

int numerador, denominador;

    numerador=(num/DivComunMaximo(num,denom));
    denominador=(denom/DivComunMaximo(num,denom));

    rtasimp[0]=numerador;
    rtasimp[1]=denominador;

return 0;
}

int sumFracciones(int num1, int denom1, int num2, int denom2, int rtasum[])
{
   int denomComun, numComun;

   denomComun=(denom1*denom2);
   numComun=((num1*denom2)+(num2*denom1));

   simpFracciones(numComun, denomComun, rtasum);

   return 0;
}

int main(){

    int numerador, denominador, numerador2, denominador2;

    int opcion=menu();

    int rta[2];

    switch (opcion)
    {
        case 1:
            numerador=getint("ingresar numerador\t");
            denominador=getint("ingresar denominador\t");
            simpFracciones(numerador,denominador, rta);
            printf("\nnumerador es %d",rta[0]);
            printf("\ndenominador es %d", rta[1]);
            break;

        case 2:
            numerador=getint("ingresar numerador\t");
            denominador=getint("ingresar denominador\t");
            numerador2=getint("ingrese numerador\t");
            denominador2=getint("ingrese denominador\t");
            sumFracciones(numerador,denominador,numerador2,denominador2,rta);
            printf("\ndenominador es %d", rta[1]);
            printf("\nnumerador es %d",rta[0]);
            break;

        case 3:
            break;
    }

return 0;
}