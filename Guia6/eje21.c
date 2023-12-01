#include <stdio.h>
#include <assert.h>
#include "../Biblioteca/getnum.h"

int menu()
{
    int opciones=getint("\nElegir opcion:\n1: Simplificar una fraccion\n2: Sumar fracciones\n3: Terminar la ejecucion\n");

return opciones;
}

int DivComunMax(int n,int m)
{
    int divisor = (n > m ? n : m);

    for (;divisor > 1; divisor--)
    {
        if (n%divisor == 0 && m%divisor == 0)
        {
            return divisor;
        }
    }
    return divisor;
}

void SimplificarFraccion(int *num, int *denom)
{
    int divcomunmax = DivComunMax(*num, *denom);

    *num = (*num / divcomunmax);

    *denom = (*denom / divcomunmax);

    return;
}

void SumarFracciones(int *num, int *denom, int *num2, int *denom2)
{
    int numerado = ((*num * *denom2) + (*num2 * *denom));

    int denominador = (*denom * *denom2);

    int divcomunmax = DivComunMax(numerado, denominador);

    *num = (numerado/divcomunmax);

    *denom = (denominador/divcomunmax);

}

void leerFraccion(int *num,int *denom)
{
    *num = getint("ingresar numerador\t");

    do  
    {   
        *denom = getint("ingresar denominador\t");
    }while(*denom==0);
}






int main()
{
    int numerador, denominador, numerador2, denominador2;

    int opcion;

do
{
    opcion = menu();

    switch (opcion)
    {
    case 1: 
        printf("ingresar fraccion\n");
        leerFraccion(&numerador, &denominador);
        SimplificarFraccion(&numerador, &denominador);
        printf("%d\n-\n%d\n",numerador, denominador);
        break;

    case 2:
        printf("ingresar fraccion\n");
        leerFraccion(&numerador, &denominador);
        printf("ingresar fraccion\n");
        leerFraccion(&numerador2, &denominador2);
        SumarFracciones(&numerador, &denominador, &numerador2, &denominador2);
        printf("%d\n-\n%d\n",numerador, denominador);
        break;
    case 3:
        break;
    }
}
while (opcion != 3);


        return 0;
}
