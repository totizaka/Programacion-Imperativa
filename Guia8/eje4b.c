#include <stdio.h>
#include "../Biblioteca/random.h"

#define CANT_CARTAS 52
#define PRIMERAS_5 5
#define DISTINTAS 13
#define PAR 1
#define PIERNA 2
#define POKER 3

void mezclarMazo(int mazo[CANT_CARTAS])
{       
    int aux;

    for (int i=0; i < CANT_CARTAS; i++)
    {   
        int carta = randInt(0, CANT_CARTAS-1);

        aux = mazo[i];

        mazo[i] = mazo[carta];

        mazo[carta] = aux;
    }
}

int poker(int mazo[], int sigRonda, int* figura)
{
    int vec[DISTINTAS]={0};
    int carta;

    for (int i=sigRonda; i < PRIMERAS_5+sigRonda; i++)
    {
        carta = (mazo[i]-2);
        
        vec[carta]++;
    }

    for (int i=0; i < DISTINTAS; i++)
    {
        if (vec[i] == 4)
        {   
            *figura = i+2;
            return POKER;
        }
        else if (vec[i] == 3)
        {   
            *figura = i+2;
            return PIERNA;
        }
        else if (vec[i] == 2)
        {
            *figura = i+2;
            return PAR;
        }
    }
    return 0;
}

int* controloMano(int i, int mazo[CANT_CARTAS], int* figura, int *resultado)
{
    *resultado = poker(mazo, i, figura);

    switch (*resultado)
    {
    case 1:
        printf("PAR\n");
        break;
    
    case 2:
        printf("PIERNA\n");
        break;
    
    case 3:
        printf("POKER\n");
        break;

    default:
        printf("nada\n");
        break;
    }
    return resultado;
}


void printeoMazo(int mazo[CANT_CARTAS])
{
    printf("mazo mezclado:");
    putchar('\n');

    for (int i = 0; i < CANT_CARTAS; i++)
    {
        printf("%d ", mazo[i]);
    }
    putchar('\n');
}


void veoGanador(int numMano, int* resultado, int* figuraAux, int* figura, int* puntosJ1, int*puntosJ2, int* puntosAux1, int* puntosAux2)
{
    if (numMano%2)
        {
            *puntosAux1+=*resultado;
        }
        else
        {
            *puntosAux2+=*resultado;

            if (*puntosAux1 == *puntosAux2)
            {
                if (*figuraAux > *figura)
                {
                    *puntosAux2=0;
                }
                else if (*figuraAux < *figura)
                {
                    *puntosAux1=0;
                }
            }
            printf("sumo %d puntos a jugador 1\n", *puntosAux1);
            printf("sumo %d puntos a jugador 2\n", *puntosAux2);

            *puntosJ1 += *puntosAux1;
            *puntosJ2 += *puntosAux2;

            *puntosAux1=0, *puntosAux2=0;
        }

        *figuraAux = *figura;    
}



int main()
{       
    randomize();

    int mazo[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};


    int puntosJ1=0, puntosJ2=0;
    int puntosAux1=0, puntosAux2=0;
    int resultado;
    int figura=0, figuraAux=0;

    mezclarMazo(mazo);

    printeoMazo(mazo);

    int numMano=1;


    for (int i = 0; i < 50; numMano++, i+=5)
    {    
        controloMano(i, mazo, &figura, &resultado);
        
        veoGanador(numMano, &resultado, &figuraAux, &figura, &puntosJ1, &puntosJ2, &puntosAux1, &puntosAux2);

    }

    printf("%d\t%d", puntosJ1, puntosJ2);
    
    putchar('\n');
}