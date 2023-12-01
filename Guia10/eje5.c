#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/utillist.h"

TList restaList (TList lista1, TList lista2)
{
    if (lista1 == NULL)
    {
        return NULL;
    }
    if (lista2 == NULL || lista1->elem < lista2->elem)
    {
        TList nuevo = malloc(sizeof(TNode));
        nuevo->elem = lista1->elem;
        nuevo->tail = restaList(lista1->tail, lista2);
        return nuevo;
    }
    if (lista1->elem > lista2->elem)
    {
        return restaList(lista1, lista2->tail);
    }
    return restaList(lista1->tail, lista2->tail);
}