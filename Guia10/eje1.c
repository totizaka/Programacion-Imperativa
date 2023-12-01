#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct node 
{
    int head;
	struct node* tail;
}Tnode;

typedef Tnode* TList; 


int sumAll(TList lista)
{
    if (lista == NULL)
    {
        return 0;
    }
    return lista->head + sumAll (lista->tail);
}


int odds1(TList lista)
{
    if (lista == NULL)
    {
        return 1;
    }
    if ((lista->head) % 2 == 0)
    {
        return 0;
    }
    return odds1(lista->tail);
}

int odds2(TList lista)
{
    if (lista == NULL)
    {
        return 0;
    }
    if ((lista->head) % 2 == 0)
    {
        return 0;
    }
    if (lista->head % 2 != 0 && lista->tail == NULL)
    {
        return 1;
    }
    return odds2(lista->tail);
}


TList add(TList list, int elem)
{
    if(list == NULL)                                                    // caso en que la lista es vacia
    {
        TList aux = malloc(sizeof(struct node));

        aux->head = elem;
        aux->tail = NULL;

        return aux;
    }
    if (elem < list->head)                                    // caso en que la lista tiene ya tiene un elem. Insertamos uno menor
    {
        TList aux = malloc(sizeof(struct node));

        aux->head = elem;
        aux->tail = list;

        return aux;
    }
    if (elem == list->head)                                  // caso en que el elem es igual al de la lista
    {
        return list;
    }
    
    list->tail = add(list->tail, elem);                      // caso en que elem es mayor que el primero.

    return list; 
}

int main()
{
    TList lista = NULL;

    lista = add(lista, 1);

    lista = add(lista, 1);

    lista = add(lista, 1);

    lista = add(lista, 9);

    printf("%d\n\n%d",sumAll(lista), odds2(lista));
}