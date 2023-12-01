#include "../PI/Codigo07ADT/stackADT.h"
#include <stdlib.h>
#include <stdio.h>

// Estructura interna para los nodos de la lista
typedef struct node {
    elemType head;
    struct node * tail;
}Tnode;

typedef struct node * TList;

struct listCDT {
    TList first;
    size_t dim; // cantidad de elementos, para hacer más eficiente la función sizeList
    compare cmp;
    TList next; // para poder iterar en forma eficiente
};

listADT newList(compare cmp) {
    listADT aux = calloc(1, sizeof(struct listCDT));
    aux->cmp = cmp;
    return aux;
}

static void freeListRec(TList list) {
    if (list == NULL) {
        return;
    }
    // Recursion de pila
    freeListRec(list->tail);
    free(list);
}

static void freeListRecTail(TList list) {
    if (list == NULL) {
        return;
    }
    // Recursion de cola
    TList aux = list->tail;
    free(list);
    freeListRecTail(aux);
}

void freeListADT(listADT list) {
    freeListRec(list->first);
    free(list);
}

// Version iterativa de liberar la lista
void freeListADTIter(listADT list) {
    TList aux = list->first;
    while (aux != NULL) {
        TList subList = aux->tail;
        free(aux);
        aux = subList;
    }
    free(list);
}

int isEmptyList(listADT list) {
    return list->dim==0;  // list->first == NULL;
}

size_t sizeList(listADT list) {
    return list->dim;
}

static int belongsRec(TList list, elemType elem, compare cmp) {
    int c;
    if(list==NULL || (c=cmp(list->head, elem)) > 0) {
        return 0;
    }
    if ( c == 0) {
        return 1;
    }
    return belongsRec(list->tail, elem, cmp);
}

int belongsList(listADT list, elemType elem) {
    return belongsRec(list->first, elem, list->cmp);
}

// trabajamos con la lista interna
// en *flag deja 1 si lo agrega,cero si no lo agrega
static TList addRec(TList list, elemType elem, compare cmp, int * flag ) {
    int c;
    if(list==NULL || (c=cmp(elem, list->head)) < 0) {
        TList aux = malloc(sizeof(Tnode));
        aux->head = elem;
        aux->tail = list;
        *flag=1;
        return aux;
    }
    if ( c > 0) {
        list->tail = addRec(list->tail, elem, cmp, flag);
    }
    return list;
}


int addList(listADT list, elemType elem) {
    int flag=0;
    list->first = addRec(list->first, elem, list->cmp, &flag);
    list->dim += flag;
    return flag;
}

static TList deleteRec(TList list, elemType elem, compare cmp, int *flag) {
    int c;
    if (list==NULL || (c=cmp(list->head, elem)) > 0) {
        return list;
    }
    if (c==0) {
        *flag=1;
        TList aux = list->tail;
        free(list);
        return aux;
    }
    // elem es mayor al primero, puede estar en la sublista
    list->tail = deleteRec(list->tail, elem, cmp, flag);
    return list;
}

int deleteList(listADT list, elemType elem) {
    int flag=0;
    list->first = deleteRec(list->first, elem, list->cmp, &flag);
    list->dim -= flag;
    return flag;
}

static elemType getRec(const TList list, size_t idx) {
    if ( idx == 0) {
        return list->head;
    }
    return getRec(list->tail, idx-1);
}

elemType getList(const listADT list, size_t idx) {
    if(list->dim <= idx ) {
        exit(1);
    }
    return getRec(list->first, idx);
}

elemType getListIter(const listADT list, size_t idx) {
    if(list->dim <= idx ) {
        exit(1);
    }
    TList aux = list->first;
    for (int i=0; i < idx; i++, aux=aux->tail)
        ;
    return aux->head;
}


void toBegin(listADT list) {
    list->next = list->first;
}

int hasNext(const listADT list) {
    return list->next != NULL;
}

elemType next(listADT list) {
    if (hasNext(list)) {
        elemType aux = list->next->head;
        list->next = list->next->tail;
        return aux;
    }
    fprintf(stderr, "No next here");
    exit(1);
}

elemType * toArray(const listADT list) {
    elemType * toReturn = malloc(list->dim * sizeof(elemType));
    TList aux = list->first;
    // No debemos usar toBegin y next porque tal vez el usuario las esté usando
    for (size_t i=0; i < list->dim; i++, aux=aux->tail) {
        toReturn[i] = aux->head;
    }
    return toReturn;
}

#define BLOCK 20

elemType * select(const listADT list, int (* criteria)(elemType), size_t * dim) {
    elemType * toReturn=NULL;
    size_t j = 0;

    TList aux = list->first;
    for (size_t i=0; i < list->dim; i++, aux=aux->tail) {
        if ( criteria(aux->head)) {
            if ( j%BLOCK==0) {
                toReturn = realloc(toReturn, (j+BLOCK) * sizeof(elemType ));
            }
            toReturn[j++] = aux->head;
        }
    }
    toReturn = realloc(toReturn, j * sizeof(elemType));
    *dim =j;
    return toReturn;
}


void mapRec(TList list, int (*criteria)(elemType))
{
    if (list == NULL)
    {
        return;
    }
    list->head = criteria(list->head);
    mapRec(list->tail, criteria);
}

listADT map(listADT list, int (*criteria)(elemType))
{
    mapRec(list->first, criteria);

    return list;
}


void mapIter(listADT list, int (*criteria)(elemType))
{
    TList aux = list->first;

    while (aux != NULL)
    {
        aux->head = criteria(aux->head);
        aux = aux->tail;
    }
}