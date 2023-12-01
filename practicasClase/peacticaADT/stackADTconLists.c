#include "stackADT.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct node {
    elemType head;
    struct node * tail;

} node;

typedef node * TList;

struct stackCDT {
    size_t dim;    // cantidad de elementos
    TList first;
    compare cmp;
};

void push(stackADT stack, elemType elem) {
    node * aux = malloc(sizeof(node));
    aux->head = elem;
    aux->tail = stack->first;
    stack->first = aux;
    stack->dim++;
}

elemType pop(stackADT stack) {
    // assert(! isEmpty(stack));
    if(isEmpty(stack)) {
        fprintf(stderr, "stack vacio al hacer pop");
        exit(1);
    }
    elemType aux = stack->first->head;
    TList secondNode =  stack->first->tail;
    free(stack->first);
    stack->first = secondNode;
    stack->dim--;
    return aux;
}

stackADT newStack(compare cmp) {
    stackADT  aux = calloc(1, sizeof(struct stackCDT));
    aux->cmp = cmp;
    return aux;
}

static void freeList(TList list) {
    if (list==NULL) {
        return;
    }
    freeList(list->tail);
    free(list);
}

void freeStack(stackADT stack) {
    // también se puede hacer iterativa, sin funcion auxiliar
    freeList(stack->first);
    free(stack);
}

int isEmpty(stackADT stack) {
    return stack->dim == 0;
}

size_t stackSize(stackADT stack) {
    return stack->dim;
}

static int belongsRec(TList list, elemType elem, compare cmp) {
    if (list == NULL) {
        return 0;
    }
    if (cmp(list->head, elem)) {
        return 1;
    }
    return belongsRec(list->tail, elem, cmp);
}

// funcion wrapper
int belongs(stackADT stack, elemType elem) {
    return belongsRec(stack->first, elem, stack->cmp);
}

int belongsIter(const stackADT stack, elemType elem) {
    node *aux = stack->first;
    while(aux!= NULL) {
        if ( stack->cmp(aux->head, elem)) {
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}