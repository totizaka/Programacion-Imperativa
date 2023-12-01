#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
#include "eje15.h"
#include <string.h>

typedef int (*compare)(elemType, elemType);

typedef struct node
{
    elemType elem;
    struct node* tail;
}Tnode;

typedef Tnode* Tlist;

typedef struct moveToFrontCDT
{
    Tlist first;
    Tlist next;
    int size;
    compare cmp;
}moveToFrontCDT;


/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío 
** La función compare retorna 0 si los elementos son iguales, negativo si e1 es 
** "menor" que e2 y positivo si e1 es "mayor" que e2
*/
moveToFrontADT newMoveToFront(int (*compare) (elemType e1, elemType e2))
{
    moveToFrontADT nuevo = calloc(1, sizeof(moveToFrontCDT));
    nuevo->cmp = compare;
    return nuevo;
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
/* Libera todos los recursos del TAD */
void freeMoveToFront(moveToFrontADT list)
{
    freeRec(list->first);
    free(list);
}


Tlist addRec(Tlist list, elemType elem, int* agrego, compare cmp)
{
    if (list == NULL)
    {
        Tlist aux = malloc(sizeof(Tnode));
        aux->elem = elem;
        aux->tail = NULL;
        *agrego=1;
        return aux;
    }
    else if (cmp(elem, list->elem)==0)
    {
        return list;
    }
    else
    {
        list->tail=addRec(list->tail, elem, agrego, cmp);
    }
    return list;
}
/* Inserta un elemento si no está. Lo inserta al final.
** Retorna 1 si lo agregó, 0 si no.
*/
unsigned int add(moveToFrontADT moveToFront, elemType elem)
{
    int agrego=0;
    moveToFront->first = addRec(moveToFront->first, elem, &agrego, moveToFront->cmp);
    moveToFront->size+=agrego;
    return agrego;
}


/* Retorna la cantidad de elementos que hay en la colección */
unsigned int size(moveToFrontADT moveToFront)
{
    return moveToFront->size;
}


/* Se ubica al principio del conjunto, para poder iterar sobre el mismo */
void toBegin(moveToFrontADT moveToFront)
{
    moveToFront->next=moveToFront->first;
}


/* Retorna 1 si hay un elemento siguiente en el iterador, 0 si no */
int hasNext(moveToFrontADT moveToFront)
{
    return (moveToFront->next != NULL); 
}

/* Retorna el siguiente elemento. Si no hay siguiente elemento, aborta */
elemType next(moveToFrontADT moveToFront)
{
    if (hasNext(moveToFront))
    {
        elemType elem = moveToFront->next->elem;
        moveToFront->next = moveToFront->next->tail;
        return elem;
    }
    exit(1);
    
}


/* Retorna una copia del elemento. Si no existe retorna NULL.
** Para saber si el elemento está, usa la función compare. 
** Si el elemento estaba lo ubica al principio.
*/
Tlist getRec(Tlist list, elemType elem, int* esta, compare cmp)
{   
    if (list==NULL)
    {
        return list;
    }
    if (cmp(elem, list->elem)==0)
    {
        Tlist aux = list->tail;
        free(list);
        esta=1;
        return aux;
    }
    list->tail = getRec(list->tail, elem, esta, cmp);
    return list;
}
Tlist addPrimero(Tlist list, elemType elem)
{
    Tlist aux = malloc(sizeof(Tnode));
    aux->elem = elem;
    aux->tail = list;
    return aux;
}
elemType * get(moveToFrontADT moveToFront, elemType elem)
{
    int esta=0;
    moveToFront->first=getRec(moveToFront->first, elem, &esta, moveToFront->cmp);
    if (esta)
    {
        moveToFront->first=addPrimero(moveToFront->first, elem);
        return elem;
    }
    return NULL;
}


