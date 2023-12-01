#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
#include "eje14.h"
#include <string.h>


typedef struct node
{
    elemType elem;
    struct node* tail;
}Tnode;

typedef Tnode* Tlist;

typedef struct listCDT
{
    Tlist listAsc;
    Tlist listIns;
    Tlist lastIns;
    Tlist nextAsc;
    Tlist nextIns;
    int size;
    compare cmp;
}listCDT;



/* Retorna una lista vacía.
** compare retorna 0 si los elementos son iguales, negativo si e1 es "menor" que e2 y 
** positivo si e1 es "mayor" que e2
*/
listADT newList(int (*compare) (elemType e1, elemType e2))
{
    listADT nuevo = calloc(1, sizeof(listCDT));
    nuevo->cmp = compare;

    return nuevo;
}



/* Agrega un elemento. Si ya estaba no lo agrega */
Tlist addRec(Tlist list, elemType elem, int* agrego, compare cmp)
{
    int c;
    if (list == NULL || (c=cmp(elem, list->elem))<0)
    {
        Tlist aux = malloc(sizeof(Tnode));
        aux->elem = elem;
        aux->tail = list;
        *agrego=1;
        return aux;
    }
    else if (c > 0)
    {
        list->tail = addRec(list->tail, elem, agrego, cmp);
    }
    return list;
}
void add(listADT list, elemType elem)
{
    int agrego=0;
    list->listAsc = addRec(list->listAsc, elem, &agrego, list->cmp);
    list->size+=agrego;
    if (agrego)
    {
        if (list->listIns == NULL)
        {
            Tlist aux = malloc(sizeof(Tnode));
            aux->elem = elem;
            aux->tail = NULL;
            list->listIns = aux;
            list->lastIns = aux;
        }
        else
        {
            Tlist aux = malloc(sizeof(Tnode));
            aux->elem = elem;
            aux->tail = NULL;
            list->lastIns->tail = aux;
            list->lastIns = aux;
        }
    }
}


/* Resetea el iterador que recorre la lista en el orden de inserción */
void toBegin(listADT list)
{
    list->nextIns=list->listIns;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en el orden de inserción. Sino retorna 0
*/
int hasNext(listADT list)
{
    return list->nextIns->tail != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista 
** en el orden de inserción. 
** Si no hay un elemento siguiente o no se invocó a toBegin aborta la ejecución.
*/
elemType next(listADT list)
{
    if (hasNext(list))
    {
        elemType elem = list->nextIns->elem;
        list->nextIns = list->nextIns->tail;
        return elem;
    }
    exit(1);
}


/* Resetea el iterador que recorre la lista en forma ascendente */
void toBeginAsc(listADT list)
{
    list->nextAsc = list->listAsc;
}


/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en forma ascendente. Sino retorna 0 
*/
int hasNextAsc(listADT list)
{
    return list->nextAsc != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en forma ascendente. 
** Si no hay un elemento siguiente o no se invocó a toBeginAsc aborta la ejecución.
*/
elemType nextAsc(listADT list)
{
    if (hasNextAsc(list))
    {
        elemType elem = list->nextAsc->elem;
        list->nextAsc = list->nextAsc->tail;
        return elem;
    }
}


void freeRec(Tlist list)
{
    if (list == NULL)
    {
        return;
    }
    freeRec(list->tail);
    free(list);
}
void freeList(listADT list)
{
    freeRec(list->lastIns);
    freeRec(list->listAsc);
    free(list);
}