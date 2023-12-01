#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Biblioteca/utillist.h"

TList listIntersec(TList lista1, TList lista2)
{
    if (lista1 == NULL || lista2 == NULL)
    {
        return NULL;
    }
    else if (lista1->elem > lista2->elem)
    {
        return listIntersec(lista1, lista2->tail);
    }
    else if (lista1->elem < lista2->elem)
    {
        return listIntersec(lista1->tail, lista2);
    }
    TList aux = malloc(sizeof(TNode));
    aux->elem = lista1->elem;
    aux->tail = listIntersec(lista1->tail, lista2->tail);
    return aux;
}

int main(void) {

  int v[] = {1, 4, 5, 6, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x[] = {2, 3, 9};

  TList l1 = fromArray(v, 6);
  TList l2 = fromArray(w, 9);
  TList l3 = listIntersec(l1, l2);
  assert(checkElems(l3, v, 6));
  assert(checkElems(l1, v, 6));
  assert(checkElems(l2, w, 9));
  freeList(l3);

  l3 = listIntersec(l2, l1);
  assert(checkElems(l3, v, 6));
  freeList(l3);

  l3 = listIntersec(l2, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listIntersec(l2, NULL);
  assert(l3==NULL);
  l3 = listIntersec(NULL, l1);
  assert(l3==NULL);
  l3 = listIntersec(NULL, NULL);
  assert(l3==NULL);
  freeList(l1);
  freeList(l2);

  l1 = fromArray(v, 6);
  l2 = fromArray(x, 3);
  l3 = listIntersec(l1, l2);
  assert(l3 == NULL);
  freeList(l3);
  freeList(l1);
  freeList(l2);

  printf ("OK!\n");
  return 0;
}