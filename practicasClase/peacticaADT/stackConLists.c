#include <stdio.h>

typedef struct node
{
    int head;
    struct node* tail;
}node;

// struct stackCDT
// {
//     node* first;
//     int dim;
// };

// static void freeList(stackADT stack)
// {
//     if (stack == NULL)
//     {
//         return;
//     }
//     freeList(stack->first);
//     free(stack);
// }

// void freeStack(stackCDT stack)
// {
//     freeList(stack->first);
// }

// void push(stackCDT stack, int elem)
// {
//     node* aux = malloc(sizeof(node));
//     aux->head = elem;
//     aux->tail = stack->first;
//     stack->first = aux;
//     stack->dim++;
// }

// int pop(stackADT stack)
// {

// }