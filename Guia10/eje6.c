#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/utillist.h"

TList deleteDupl(TList lista)
{
    if (lista == NULL || lista->tail == NULL)
    {
        return lista;
    }
    if (lista->elem == lista->tail->elem)
    {
        TList aux = lista->tail;
        free(lista);
        deleteDupl(aux);
    }
    deleteDupl(lista->tail);
    
    return lista;
}

TList deleteDupl2(TList lista)
{
    if (lista == NULL || lista->tail == NULL)
    {
        return lista;
    }
    if (lista->elem == lista->tail->elem)
    {
        TList aux = lista->tail;
        lista->tail = aux->tail;
        free(aux); 
        deleteDupl2(lista);
        return;
    }
    deleteDupl2(lista->tail);
}