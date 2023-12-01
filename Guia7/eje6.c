#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

#define X 6
#define N 3

void GeneraAleatorio(int vec[])
{
    int vecaux[]={1,2,3,4,5,6,7,8,9};
    int i, n=9, aux;

    for (i = 0; i < X; i++)
    {   
        aux = randInt(0, n-1);

        vec[i] = vecaux[aux];

        vecaux[aux] = vecaux[n-1];

        n--;

        printf("%d", vec[i]);
    }
}

int elegirNivel()
{
    int nivel;
    do
    {
       nivel = getint("ingresar nivel\n");

    } while (nivel > 10 || nivel < 1);

    return nivel;
}

void ingresarNumero(int num[])
{
    int numero, ok;
    do
    {  
        int vecaux[10]={0};
        int iterador=(X-1), numaux;

        ok=1;
        numero = getint("\ningresar numero de %d cifras utilizando numeros del 1 al 9\n", X);

        while (ok && iterador >= 0)
        {
            numaux = numero%10;
            vecaux[numaux]++;

            if (vecaux[numaux]<2 && numaux!=0)
            {
                num[iterador]=numaux;    
            }
            else
            {   
                ok=0;
            }
            iterador--;
            numero/=10;
        }
                                        //9475
    } while (!ok || numero!=0);

}

int regular(int incognita[], int vec[])
{
    int regular=0;

    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < X; j++)
        {
            if ( i!=j && vec[i]==incognita[j])
            {
                regular++;
            }
        }
    }
    return regular;
}

int bien(int incognita[], int vec[])
{
    int bien=0;

    for (int i = 0; i < X; i++)
    {
        if (vec[i]==incognita[i])
        {
            bien++;
        }
    }
    return bien;
}

int coincideNumero(int incognita[], int vec[])
{
    if (bien(incognita, vec) == X)
    {
        printf("\nel numero es correcto\n");

        return 0;
    }
    else
    {
        printf("\n%d bien, %d regular\n", bien(incognita, vec), regular(incognita, vec));

        return 1;
    }
}



int main()
{
    int incognita[X];
    int numero[X];

    int nivel, iguales=1;

    GeneraAleatorio(incognita);

    nivel=elegirNivel();
    
    for (int i=0; i < nivel && iguales; i++)
    {
        ingresarNumero(numero);

        iguales = coincideNumero(incognita, numero);
    }
    return 0;
}