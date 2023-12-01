#include <stdio.h>
#include <stdlib.h>

struct node
{
    int head;
    struct node* tail;
};

typedef struct node* List;

int isEmpty(const List list)
{
    return list == NULL;
}

size_t size(const List list)
{
    if (list == NULL)
    {
        return 0;
    }
    return (1 + size((*list).tail));
}

int belongs(const List list, int elemento)
{
    if (list == NULL || list->head > elemento)
    {
        return 0;
    }
    
    else if (list->head == elemento)
    {
        return 1;
    }
    return (belongs(list->tail, elemento));
}

size_t sizeIter(const struct node* list)
{
    size_t cant = 0;

    while (list != NULL)
    {
        cant++;
        list = list->tail;
    }
    return cant;
}


List add(List list, int elem)
{
    if(list == NULL)                                                    // caso en que la lista es vacia
    {
        List aux = malloc(sizeof(struct node));

        aux->head = elem;
        aux->tail = NULL;

        return aux;
    }
    if (elem < list->head)                                    // caso en que la lista tiene ya tiene un elem. Insertamos uno menor
    {
        List aux = malloc(sizeof(struct node));

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

List delete(List list, int elem)
{
    if (list == NULL || elem < list->head)
    {
        return list;
    }
    if (elem == list->head)
    {
        List aux = list->tail;
        free(list);

        return aux;
    }

    list->tail = delete(list->tail, elem);
    
    return list;
}

void freeList(List list)
{
    if (list == NULL)
    {
        return;
    }

    freeList(list->tail);
    free(list);
}



int head(List list) {
    if ( list == NULL) {
        fprintf(stderr, "list cant be NULL");
        exit(1);
    }
    return list->head;
}

List tail(List list) {
    if ( list == NULL) {
        fprintf(stderr, "list cant be NULL");
        exit(1);
    }
    return list->tail;
}


int
main(void) {
   List myList = NULL;
   assert(size(myList)==0);
   assert(belongs(myList, 10)==0);

   myList = add(myList, 10);
   assert(size(myList)==1);
   assert(belongs(myList, 10)==1);
   assert(belongs(myList, 20)==0);

    myList = add(myList, 5);
    assert(size(myList)==2);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 5)==1);

    myList = add(myList, 5);
    myList = add(myList, 10);

    assert(size(myList)==2);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 5)==1);

    myList = add(myList, 55);  // al final
    myList = add(myList, 20);  //  en el medio
    assert(size(myList)==4);
    assert(belongs(myList, 10)==1);
    assert(belongs(myList, 5)==1);

    myList = delete(myList, 10);
    assert(size(myList)==3);
    assert(belongs(myList, 10)==0);
    assert(belongs(myList, 5)==1);

    // Quiero imprimir todos los elementos, o sumarlos
    List aux = myList;
    while(! isEmpty(aux)) {
        printf("%d ", head(aux));
        aux = tail(aux);
    }
    putchar('\n');

    /*
   int cant = size(myList);
   for(int i=0; i < cant; i++) {
       printf("%d ", get(myList, i));
   }
   putchar('\n');
     */

   freeList(myList);
   puts("OK!");
   return 0;
}