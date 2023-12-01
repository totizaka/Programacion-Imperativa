#ifndef __STACKADT_H
#define __STACKADT_H

#include<stdio.h>
#include <stdlib.h>

typedef struct stackCDT * stackADT;

// Con un typedef definimos el tipo de dato a utilizar
// El usuario debe cambiar este typedef y recompilar el .c
typedef struct point{int x; int y;} elemType;

typedef int (*compare) (elemType e1, elemType e2);

/**
 *
 * @param cmp funcion para poder comparar dos elementos, 1 si son iguales, 0 sinó
 * @return
 */
stackADT newStack( compare cmp);

int isEmpty(stackADT stack);

/**
 *
 * @param stack
 * @return cantidad de elementos en el stack
 */
size_t stackSize(stackADT stack);

void push(stackADT stack, elemType elem);

/**
 *
 * @param stack
 * @return el elemento del tope. Aborta si la pila estaba
 * vacía
 */
elemType pop(stackADT stack);

void freeStack(stackADT stack);

// Retorna 1 si elem está en el stack
// Sólo con fines académicos
int belongs(stackADT stack, elemType elem);

#endif