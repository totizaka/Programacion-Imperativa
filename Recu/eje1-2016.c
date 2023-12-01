#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int elem;
    struct node* tail;
}Tnode;

typedef Tnode* Tlist;

Tlist deleteAll(Tlist list1, Tlist list2)
{
    if (list1 == NULL || list2 == NULL)
    {
        return list1;
    }
    if (list1->elem > list2->elem)
    {
        return deleteAll(list1, list2->tail);
    }
    else if (list1->elem < list2->elem)
    {
        list1->tail = deleteAll(list1->tail, list2);
        return list1;
    }
    else
    {
        Tlist aux = list1->tail;
        free(list1);
        return deleteAll(list1, list2->tail);
    }
}