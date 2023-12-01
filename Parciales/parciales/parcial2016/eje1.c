#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
// #include "eje1.h"
#include <string.h>

typedef struct node{
    int elem;
    struct node* tail;
}Tnode;

typedef struct node* Tlist;

Tlist deleteAll(Tlist list1, Tlist list2)
{
    if (list1 == NULL || list2 == NULL)
    {
        return list1;
    }
    else if (list1->elem == list2->elem)
    {
        Tlist aux = list1->tail;
        free(list1);
        return deleteAll(aux, list2->tail);
    }
    else if (list1->elem < list2->elem)
    {
        list1->tail = deleteAll(list1->tail, list2);
        return list1;
    }
    return deleteAll(list1, list2->tail);
    
}




