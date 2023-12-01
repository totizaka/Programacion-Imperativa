#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
// #include "eje17.h"
#include <string.h>

typedef struct node{
int elem;
struct node * tail;
} Tnode;

typedef Tnode* TList;

TList delete(TList list)
{
    if (list == NULL || list->tail == NULL)
    {
        return list;
    }
    if (list->elem >= list->tail->elem)
    {
        TList aux = list->tail;
        list->tail = list->tail->tail;
        free(aux);
        return delete(list);
    }
    list->tail = delete(list->tail);
    delete(list->tail);    
}
