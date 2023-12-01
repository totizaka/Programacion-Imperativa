#include "stackADT.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define BLOCK 20

struct stackCDT {
    elemType * vec;
    size_t dim; // cantidad de elementos
    size_t size;    // cantidad de posiciones reservadas
    int (*cmp) (elemType e1, elemType e2);
};

void push(stackADT stack, elemType elem) {
    if ( stack->size == stack->dim) {
        stack->size += BLOCK;
        stack->vec = realloc(stack->vec, stack->size * sizeof(stack->vec[0]));
    }
    stack->vec[stack->dim++] = elem;
    return;
}

elemType pop(stackADT stack) {
    
    if(isEmpty(stack)) {
        fprintf(stderr, "stack vacio al hacer pop");
        exit(1);
    }
    //elemType aux = stack->vec[stack->dim-1];
    //stack->dim--;
    //return aux;
    return stack->vec[--stack->dim];
}

stackADT newStack( int (*cmp) (elemType e1, elemType e2)) {
    stackADT aux = calloc(1, sizeof(struct stackCDT));
    aux->cmp = cmp;
    return aux;
}

void freeStack(stackADT stack) {
    free(stack->vec);
    free(stack);
}

int isEmpty(stackADT stack) {
    return stack->dim == 0;
}

size_t stackSize(stackADT stack) {
    return stack->dim;
}

int belongs(stackADT stack, elemType elem) {
    for(size_t i=0; i < stack->dim; i++) {
        if ( stack->cmp(stack->vec[i], elem)) {
            return 1;
        }
    }
    return 0;
}
