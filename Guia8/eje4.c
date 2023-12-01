#include <stdio.h>
#include "../Biblioteca/random.h"

#define CANT_CARTAS 52
#define PRIMERAS 5
#define DISTINTAS 13
#define PAR 1
#define PIERNA 2
#define POKER 3

void mezclarMazo(int mazo[CANT_CARTAS])
{       
    int aux;

    for (int i; i < CANT_CARTAS; i++)
    {   
        int carta = randInt(0, CANT_CARTAS);

        aux = mazo[i];

        mazo[i] = mazo[carta];

        mazo[carta] = aux;
    }
}

int poker(int mazo[])
{
    int vec[DISTINTAS]={0};
    int carta;

    for (int i = 0; i < PRIMERAS; i++)
    {
        carta = (mazo[i]-2);
        
        vec[carta]++;
    }

    for (int i = 0; i < DISTINTAS; i++)
    {
        if (vec[i] == 4)
        {
            return POKER;
        }
        else if (vec[i] == 3)
        {
            return PIERNA;
        }
        else if (vec[i] == 2)
        {
            return PAR;
        }
    }
    return 0;
}

int main()
{       
    int mazo[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 
                    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    randomize();

    mezclarMazo(mazo);

    printf("mazo mezclado:");
    putchar('\n');

    for (int i = 0; i < CANT_CARTAS; i++)
    {
        printf("%d ", mazo[i]);
    }
    putchar('\n');

    switch (poker(mazo))
    {
    case 1:
        printf("PAR");
        break;
    
    case 2:
        printf("PIERNA");
        break;
    
    case 3:
        printf("POKER");
        break;

    default:
        printf("nada");
        break;
    }
    
    putchar('\n');
}