#include <stdio.h>

int mezclar(int vec[], int dim, int resp[]){

int aux, cambio;

for ( int it1 = 0; it1 < dim; it1++ )
{
    cambio=randint(0,dim-1);
    aux=vec[it1];

    vec[it1] = vec[cambio];

    vec[cambio] = vec[it1];
}

return vec;

}