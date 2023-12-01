#include <stdio.h>
#include <stdlib.h>
#include "eje2-2023.h"

typedef int (*compare)(landmarkType , landmarkType);

typedef struct{
    int dim;
    char* names[20];
}landmarkType;

typedef struct {
    landmarkType nombre;
    char occupied;
}Tsite;

typedef struct landmarkCDT {
    size_t dim;     // cantidad de sitios de interés
    size_t size;    // cantidad de elementos reservados
    Tsite * v;       // vector con los sitios de interés
    compare cmp;
}landmarkCDT;

/**
* Crea una nueva colección de sitios de interés. Sólo se registrará un sitio cada
* 100 metros (uno entre los 0 y 99 metros, posiblemente otro entre los 100 y 199, etc.)
*/
landmarkADT newLandmark(compare cmp)
{
    landmarkADT nuevo = calloc(1, sizeof(landmarkCDT));
    nuevo->cmp = cmp;
    return nuevo;
}

/**
* Agrega un punto de interés #site a #meters metros del origen. Si ya había
* un sitio, sólo queda #site (ver programa de testeo)
*/
void addLandmark(landmarkADT landmark, size_t meters, landmarkType site)
{
    size_t distancia = meters / 100;
    if ( distancia >= landmark->size)
    {
        size_t newSize = distancia+1;
        landmark->v = realloc(landmark->v, newSize * sizeof(landmark->v[0]));
        for(size_t i = landmark->size; i < newSize; i++) {
            landmark->v[i].occupied = 0;
        }
        landmark->size = newSize;
    }
    // Si no estaba ocupada, incrementamos dim
    if (! landmark->v[distancia].occupied) {
        landmark->v[distancia].occupied = 1;
        landmark->dim++;
    }
    landmark->v[distancia].nombre = site;
}

/*
* Retorna un vector con los sitios de interés, en orden ascendente por distancia
* al origen. Si no hubiera sitios de interés retorna NULL
*/
landmarkType * landmarks(const landmarkADT landmark)
{
    if (landmark == NULL)
    {
        return NULL;
    }
    landmarkType* vecret = malloc(landmark->dim * sizeof(landmarkType));
    int j=0;
    for (int i = 0; i < landmark->size; i++)
    {
        if (landmark->v[i].occupied)
        {
            vecret[j++] = landmark->v[i].nombre;
        }
    }
    return vecret;
}