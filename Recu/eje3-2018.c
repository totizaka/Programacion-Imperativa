#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "eje3-2018.h"

typedef int (*compare)(elemType,elemType);

typedef struct node{
    elemType elem;
    struct node* tail;
}Tnode;

typedef Tnode* Tlist;

typedef struct listCDT{
    Tlist fisrtAsc;
    Tlist firstIns;
    Tlist lastIns;
    Tlist nextAsc;
    Tlist nextIns;
    compare cmp;
    size_t size;
}listCDT;


/* Retorna una lista vacía.
*/
listADT newList(compare cmp)
{
    listADT nuevo = calloc(1, sizeof(listCDT));
    nuevo->cmp = cmp;
    return nuevo;
}

/* Agrega un elemento. Si ya estaba no lo agrega */
Tlist addRec(Tlist list, elemType elem, compare cmp, int* agrego)
{
    int c;
    if (list == NULL || (c=cmp(list->elem, elem))>0)
    {
        Tlist aux = malloc(sizeof(Tnode));
        aux->elem = elem;
        aux->tail = list;
        *agrego = 1;
        return aux;
    }
    if (c == 0)
    {
        return list;
    }
    list->tail = addRec(list->tail, elem, cmp, agrego);
    return list;
}
void add(listADT list, elemType elem)
{
    int agrego=0;
    list->fisrtAsc = addRec(list->fisrtAsc, elem, list->cmp, &agrego);
    if (agrego)
    {   
        if (list->size == 0)
        {
            Tlist aux = malloc(sizeof(Tnode));
            aux->elem = elem;
            aux->tail = NULL;
            list->firstIns = aux;
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
    list->size+=agrego;
}

/* Elimina un elemento. */
Tlist removeRec(Tlist list, elemType elem, compare cmp, int* elimine)
{
    int c;
    if (list == NULL || (c=cmp(list->elem, elem))>0)
    {
        return list;
    }
    else if( c == 0)
    {
        Tlist aux = list->tail;
        free(list);
        *elimine=1;
        return aux;
    }
    list->tail = removeRec(list->tail, elem, cmp, elimine);
    return list;
}
void remove(listADT list, elemType elem)
{
    int elimine=0;
    list->fisrtAsc = removeRec(list->fisrtAsc, elem, list->cmp, elimine);
    if (elimine)
    {
        Tlist aux = list->firstIns;
        while (aux->tail != NULL)
        {
            if (aux->tail->elem == elem)
            {
                Tlist aux2 = aux->tail;
                aux->tail = aux->tail->tail;
                free(aux2);
            }
            aux = aux->tail;
        }
    }
    list->size-=elimine;
}

/* Resetea el iterador que recorre la lista en el orden de inserción */
void toBegin(listADT list)
{
    list->nextIns = list->firstIns;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en el orden de inserción. Sino retorna 0 */
int hasNext(listADT list)
{
    if (list->nextIns->tail != NULL)
    {
        return 1;
    }
    return 0;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en el orden de inserción.
** Si no hay un elemento siguiente o no se invocó a toBegin aborta la ejecución.
*/
elemType next(listADT list)
{
    if (hasNext)
    {
        elemType elem = list->nextIns->elem;
        list->lastIns = list->nextIns->tail;
        return elem;
    }
    exit(1);
}

/* Resetea el iterador que recorre la lista en forma ascendente */
void toBeginAsc(listADT list)
{
    list->nextAsc = list->fisrtAsc;
}
/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en forma ascendente. Sino retorna 0 */
int hasNextAsc(listADT list)
{
    if (list->nextAsc != NULL)
    {
        return 1;
    }
    return 0;
}
/* Retorna el elemento siguiente del iterador que recorre la lista en forma ascendente.
** Si no hay un elemento siguiente o no se invocó a toBeginAsc aborta la ejecución.
*/
elemType nextAsc(listADT list)
{
    if (hasNextAsc)
    {
        elemType elem = list->nextAsc->elem;
        list->nextAsc = list->nextAsc->tail;
        return elem;
    }
    exit(1);
}