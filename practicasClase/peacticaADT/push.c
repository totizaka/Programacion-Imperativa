#include <stdio.h>
#define BLOQUE 20

struct stackCDT
{
    int* vec;
    size_t dim;
    size_t size;
};


// void push(stackADT stack, int elem)
// {
//     if (stack->dim == stack->size)
//     {
//         stack->size += BLOQUE;
//         stack->vec = realloc(stack->vec, stack->size * sizeof(int));
//     }
//         stack->vec[stack->dim] = elem;
        
//         stack->dim += 1;
// }


// int pop(stackADT stack)
// {
//     if (isEmpty)
//     {
//         exit(1);
//     }
//     int aux = stack->vec[stack->dim-1];
//     stack->dim -= 1;
//     return aux;
// }