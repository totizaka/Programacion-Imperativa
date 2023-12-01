#include <stdio.h>

typedef struct node {
int elem;
struct node * tail;
} TNode;

typedef struct node * TList;


TList sortedList(TList list)
{
    if (list == NULL)
    {
        return list;
    }
    TList aux = sortedList(list->tail);

    if (list->elem >= aux->elem)
    {
        free(list);
        return aux;
    }
    list->tail = aux;
    return list;
}