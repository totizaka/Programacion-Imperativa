#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/random.h"

#define BLOQUE 5
#define MAX_X 3
#define MAX_Y 3

typedef struct
{
    int x;
    int y;
} tPunto2D;

int main()
{
    randomize();

    tPunto2D particula;

    particula.x = 0;
    particula.y = 0;

    int dim=0;

    typedef tPunto2D* tPosiciones;

    tPosiciones arregloPos=NULL;

    int aleatorio_x, aleatorio_y;
    do
    {
        aleatorio_x = randInt(-MAX_X-1, MAX_X);
        aleatorio_y = randInt(-MAX_Y-1, MAX_Y);

        particula.x = aleatorio_x;
        particula.y = aleatorio_y;

        if (dim % BLOQUE == 0)
        {
            arregloPos = realloc(arregloPos, (dim + BLOQUE) * sizeof(tPunto2D));
        }
        (arregloPos[dim]).x = particula.x;
        (arregloPos[dim]).y = particula.y;
        
        dim++;

        // printf("%d y %d\n", particula.x, particula.y);
    } while (particula.x != 0 || particula.y != 0);
    
    for (int i = 0; i < dim; i++)
    {
        printf("%d y %d\n", arregloPos[i].x, arregloPos[i].y);
    }
    printf("%d", dim);
}