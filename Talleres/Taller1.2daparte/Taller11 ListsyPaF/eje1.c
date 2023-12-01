#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int head;
    struct node* tail;
}Tnode;

// list1 1   2   3   NULL
// list2 NULL

typedef Tnode* Tlist;

Tlist concatenarLista(Tlist lista1, Tlist lista2)
{
    if (lista1 == NULL && lista2 != NULL)
    {
        Tlist newNode = malloc(sizeof(Tnode));
        newNode->head = lista2->head;
        newNode->tail = concatenarLista(NULL, lista2->tail);
        return newNode;
    }
    else if (lista1 != NULL && lista2 != NULL)
    {
        lista1->tail = concatenarLista(lista1->tail, lista2);
    }
    return lista1;
}