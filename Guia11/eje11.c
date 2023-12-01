#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
#include "../PI/Guia11/eje11.h"
#include <strings.h>



typedef struct Tvec
{
    elemType elem;
    int ocupado;                             // 1 si esta ocupado y 0 si esta libre
}Tvec;

typedef struct vectorCDT
{
    size_t cantElems;                               // cant elementos insertados
    size_t size;                                    // cant de lugares reservados
    Tvec* vector;                                    // mi vector de elementos
    compare cmp;
}vectorCDT;



vectorADT newVector(compare cmp)
{
    vectorADT nuevo = calloc(1, sizeof(vectorCDT));
    nuevo->cmp = cmp;
    return nuevo;
}



void freeVector(vectorADT vector)
{   
    free(vector->vector);
    free(vector);
}



int put(vectorADT vec, elemType * elems, size_t dim, size_t index)
{
    int ultimolugar = index + dim;
    if (ultimolugar > vec->size)
    {
        vec->vector = realloc(vec->vector, ultimolugar * sizeof(Tvec));
        for (int i = vec->size; i < ultimolugar; i++)
        {
            vec->vector[i].ocupado = 0;
        }
        vec->size = ultimolugar;
    }
    int cantAgregados=0;
    for (int i = index, j=0; i < ultimolugar; i++, j++)
    {   
        if (vec->vector[i].ocupado == 0)
        {
            vec->vector[i].ocupado = 1;
            vec->vector[i].elem = elems[j];
            cantAgregados++;
        }
    }
    vec->cantElems+=cantAgregados;
}



int getIdx(vectorADT vec, elemType elem)
{
    for (int i = 0; i < vec->size; i++)
    {
        if (vec->vector[i].ocupado && vec->cmp(vec->vector[i].elem, elem) == 0)
        {
            return i;
        }
    }
    return -1;
}



void deleteElement(vectorADT vec, size_t index)
{
    if (index > vec->size)
    {
        return;
    }
    if (vec->vector[index].ocupado)
    {
        vec->vector[index].elem = 0;
        vec->vector[index].ocupado = 0;
    }
    return;
}



int elementCount(vectorADT vec)
{
    return vec->cantElems;
}