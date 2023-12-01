#include <stdio.h>
#include "../Biblioteca/random.h"

int mezclar(int vec[], int dim){

int aux;

for (int i = 0; i < dim; i++)
{
    int pos = randInt(0, dim-1);

    int aux = vec[i];

    vec[i] = vec[pos];

    vec[pos] = aux;

}

}