#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int head;

    struct node* tail;    
}Tnode;

typedef struct Tnode* List;

List strToListUpper(char* vec)
{
    if (*vec == 0)
    {
        return NULL;
    }
    if (*vec >= 'A' && *vec <= 'Z')
    {
        Tnode *nuevo = malloc(sizeof(Tnode));
        nuevo->head = *vec;
        nuevo->tail = strToListUpper(vec+1);
        return nuevo;
    }
    return strToListUpper(vec+1);
}

void showList;

