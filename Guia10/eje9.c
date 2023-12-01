#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Biblioteca/utillist.h"

typedef struct nodeBrief {
		int elem;
		size_t count;
		struct nodeBrief * tail;
	} TNodeBrief;

typedef struct nodeBrief * TListBrief;


TListBrief comprimeList(TList lista)
{
    if (lista == NULL)
    {
        return NULL;
    }
    TListBrief aux = comprimeList(lista->tail);

    if (aux == NULL || lista->elem < aux->elem)
    {
        TListBrief listabr = malloc(sizeof(TNodeBrief));
        listabr->elem = lista->elem;
        listabr->count = 1;
        listabr->tail = aux;
        return listabr;
    }
    aux->count++;
    return aux;
    
}