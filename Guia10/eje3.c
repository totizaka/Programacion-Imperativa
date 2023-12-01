#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/utillist.h"

TList order(TList lista)
{
    if (lista == NULL || lista->tail == NULL)
        return lista;

    if (lista->elem > lista->tail->elem)
    {
        TList aux = lista->tail->tail;
        free(lista->tail);
        lista->tail = order(aux);
    }
    lista->tail = order(lista->tail);

    return lista;
}