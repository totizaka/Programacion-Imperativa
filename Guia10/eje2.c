#include <stdio.h>
#include <stdlib.h>

struct node
{
    int head;

    struct node* tail;
};

typedef struct node* TList;

TList delete(TList lista, int elem)
{
    if (lista == NULL)
    {
        return lista;
    }
    if (lista->head == elem)
    {
        TList aux = lista->tail;
        
        free (lista);

        return aux;
    }
    
    lista->tail = delete (lista->tail, elem);

    return lista;
}

int get(TList lista, unsigned int i)
{
    if (lista == NULL)
    {
        exit(1);
    }
    if (i == 0)
    {
        return lista->head;
    }
    get(lista->tail, i-1);
}