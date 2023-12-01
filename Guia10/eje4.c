#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/utillist.h"

TList addAll(TList lista1, TList lista2)
{
    if (lista2 == NULL)
    {
        return lista1;
    }
    if (lista1->elem < lista2->elem)
    {
        lista1->tail = addAll(lista1->tail, lista2);
    }
    else if (lista1->elem == lista2->elem)
    {
        lista1->tail = addAll(lista1->tail, lista2->tail);
    }
    else if (lista1 == NULL || lista1->elem > lista2->elem)
    {
        TList nuevo = malloc(sizeof(TNode));
        nuevo->elem = lista2->elem;
        nuevo->tail = addAll(lista1, lista2->tail);
        return nuevo;
    }
    return lista1;
}