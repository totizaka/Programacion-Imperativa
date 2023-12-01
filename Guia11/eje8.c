#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/utillist.h"
#include <assert.h>
// #include "PI/Codigo07ADT/stackADT.h"

typedef int elemType;

typedef elemType (* compare) (elemType, elemType);

typedef struct node{
    elemType head;
    struct node* tail;
}Tnode;

typedef Tnode* Tlist;

typedef struct listCDT{
    Tlist first;
    size_t dim;
    compare cmp;
    TList next;
}listCDT;

typedef listCDT* listADT;


typedef struct setCDT{
    listADT list;
    compare compare;
}setCDT;

typedef setCDT* setADT;


listADT newList(compare cmp)
{
    listADT nuevaLista = calloc(1, sizeof(listCDT));
    nuevaLista->cmp = cmp;
    return nuevaLista;
}
setADT newSet(compare cmp)
{
    setADT nuevoSet = malloc(sizeof(setCDT));

    nuevoSet->list = newList(cmp);
    nuevoSet->compare = cmp;
    
    return nuevoSet;
}


void freeListRec(TList list)
{
    if (list == NULL)
    {
        return;
    }
    freeListRec(list->tail);
    free(list);
}
void freeSet(setADT set)
{   
    freeListRec(set->list->first);
    free(set->list);
    free(set);
}


int isEmpty(setADT set)
{
    if (set->list->first == NULL)
    {
        return 1;
    }
    return 0;
}


int containsListRec(TList list, elemType element)
{
    if (list == NULL)
    {
        return 0;
    }
    if (list->elem == element)
    {
        return 1;
    }
    return containsListRec(list->tail, element);
}
int setContains(const setADT set, elemType element)
{
    return containsListRec(set->list->first, element);
}


TList addList(TList list, elemType element, elemType (*compare)(elemType, elemType), int* agrego)
{
    int c;
    if (list == NULL || (c=compare(element, list->elem))<0)
    {
        TList aux = malloc(sizeof(Tnode));
        aux->elem = element;
        aux->tail = list;
        *agrego=1;
        return aux;
    }
    if (c > 0)
    {
        list->tail = addList(list->tail, element, compare, agrego);
    }
    return list;
}
int addElement(setADT set, elemType element)
{
    int agrego=0;
    set->list->first = addList(set->list->first, element, set->compare, &agrego);
    set->list->dim+=agrego;
    return agrego;
}


TList deleteElemList(TList list, elemType element, elemType (*compare)(elemType, elemType), int* elimino)
{   
    int c;
    if (list == NULL || (c=compare(element, list->elem))<0)
    {
        return list;
    }
    if (c == 0)
    {
        TList aux = list->tail;
        free(list);
        elimino == 1;
        return aux;
    }
    list->tail = deleteElemList(list->tail, element, compare, elimino);
    return list;
}
int deleteElement(setADT set, elemType element)
{
    int elimino=0;
    set->list->first = deleteElemList(set->list->first, element, set->compare, &elimino);
    set->list->dim -= elimino;
    return elimino;
}


int sizeSet(const setADT set)
{
    return set->list->dim;
}


setADT unionSet(setADT set1, setADT set2)
{
    setADT setUnion = newSet(set1->compare);
    listADT aux1 = set1;
    listADT aux2 = set2;

    int aux1dim = set1->list->dim;
    int aux2dim = set2->list->dim;

    while (aux1dim != 0 && aux2dim != 0)
    {
        if (aux1->first->head < aux2->first->head)
        {
            addElement(setUnion, aux1->first->head);
            aux1->first = aux1->first->tail;
        }
        else if (aux1->first->head > aux2->first->head)
        {
            addElement(setUnion, aux2->first->head);
            aux2->first = aux2->first->tail;
        }
        else
        {
            addElement(setUnion, aux1->first->head);
            aux1->first = aux1->first->tail;
            aux2->first = aux2->first->tail;
        }
    }
    return setUnion;
}


setADT interseccionSet(setADT set1, setADT set2)
{
    setADT setInter = newSet(set1->compare);
    listADT aux1 = set1->list;
    listADT aux2 = set2->list;

    int aux1dim = set1->list->dim;
    int aux2dim = set2->list->dim;

    while(aux1dim != 0 && aux2dim != 0)
    {
        if (aux1->first->head < aux2->first->head)
        {
            aux1dim-=1;
            aux1->first = aux1->first->tail;
        }
        else if (aux1->first->head > aux2->first->head)
        {
            aux2dim-=1;
            aux2->first = aux2->first->tail;
        }
        else
        {
            addElement(setInter, aux1->first->head);
            aux1dim-=1;
            aux1->first = aux1->first->tail;
            aux2dim-=1;
            aux2->first = aux2->first->tail;
        }
    }
    return setInter;
}


setADT diffSet(setADT set1, setADT set2)
{
    setADT diffSet = newSet(set1->compare);
    listADT aux1 = set1->list;
    listADT aux2 = set2->list;

    int aux1dim = aux1->dim;
    int aux2dim = aux2->dim;

    while (aux1dim != 0 && aux2dim != 0)
    {
        if (aux1->first->head > aux2->first->head)
        {
            addElement(diffSet, aux1->first->head);
            aux1->first = aux1->first->tail;
        }
        else if (aux1->first->head < aux2->first->head)
        {
            addElement(diffSet, aux2->first->head);
            aux2->first = aux2->first->tail;
        }
        else
        {
            deleteElement(diffSet, aux1->first->head);
        }
    }
    return diffSet;
}

