#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Biblioteca/utillist.h"

TList listUnion(TList lista1, TList lista2)
{
    if (lista1 == NULL && lista2 == NULL)
    {
        return NULL;
    }
    else if ((lista1 == NULL && lista2 != NULL) || (lista1->elem > lista2->elem))
    {
        TList aux = malloc(sizeof(TNode));
        aux->elem = lista2->elem;
        aux->tail = listUnion(lista1, lista2->tail);
        return aux;
    }
    else if ((lista2 == NULL) || (lista1->elem < lista2->elem))
    {
        TList aux = malloc(sizeof(TNode));
        aux->elem = lista1->elem;
        aux->tail = listUnion(lista1->tail, lista2);
        return aux;
    }
    else
    {
        TList aux = malloc(sizeof(TNode));
        aux->elem = lista1->elem;
        aux->tail = listUnion(lista1->tail, lista2->tail);
        return aux;
    }
}

int main(void) {

  int v[] = {1, 4, 5, 6, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x[] = {2, 3, 9};

  TList l1 = fromArray(v, 6);
  TList l2 = fromArray(w, 9);
  TList l3 = listUnion(l1, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l1);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, NULL);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(NULL, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);
  freeList(l1);
  freeList(l2);
  
  l1 = fromArray(v, 6);
  l2 = fromArray(x, 3);
  l3 = listUnion(l1, l2);
  freeList(l1);
  freeList(l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);


  printf ("OK!\n");
  return 0;
}