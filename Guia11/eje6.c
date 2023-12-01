#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/utillist.h"
#include <assert.h>

typedef int elemtype;

elemtype getElem(TList list, int i)
{
    if (list == NULL)
    {
        return NULL;
    }
    if (i==0)
    {
        return list->elem;
    }
    return getElem(list->tail, i-1);
}