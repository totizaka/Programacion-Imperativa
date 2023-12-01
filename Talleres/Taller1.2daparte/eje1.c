#include <stdio.h>
#include <stdlib.h>
#include "../Getnum/getnum.h"

#define TAM 10

int checkNum(int *vec, int dim, int num)
{
    int esta=0;
    for (int i=0; i < dim; i++)
    {   
        if(num == vec[i])
        {   esta++;
        }
    }
    if (esta==1)
    {
        return 0;
    }
    return 1;
}

int* cargaNumeros(int *dim)
{
    int* vec = NULL;

    int num, repe=1;
    *dim = 0;

    do{
        if (*dim % TAM == 0)
        {
            vec = realloc(vec, (*dim+TAM)*sizeof (int));
        }
        num = getint("ingresar numero");

        if (checkNum(vec, *dim, num))
        {
            vec[(*dim)++]=num;
        }
        else
            repe=0;
    }
    while(repe);
    
    vec = realloc(vec, *dim*sizeof(int));

    return vec;
}

int main()
{
    int dim;
    int *arr;

    arr = cargaNumeros(&dim);

    for (int i=0; i<dim; i++)
        printf("%d", arr[i]);

    free(arr);
    return 0;
}