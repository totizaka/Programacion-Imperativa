#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
#include "eje2.h"
#include <string.h>

typedef int(*compare)(elemType,elemType);

typedef struct node
{
    int elem;
    struct node* tail;
}Tnode;

typedef Tnode* Tlist;

typedef struct setCDT
{
    Tlist first;
    size_t size;
    elemType max;
    elemType min;
    elemType last;
    compare cmp;
}setCDT;


//Retorna un nuveo conjunto de elementos genericos. Al principio estÃ¡ vacio
setADT newSet(compare cmp)
{
    setADT nuevo = calloc(1,sizeof(setCDT));
    nuevo->cmp = cmp;
    return nuevo;
}

//Inserta una copia superficial de elem siempre y cunado el elemento no estÃ© en el conjunto. 
//Retorna la cantidad total de elementos luego de agregar el elemento nuevo
Tlist addRec(Tlist lista, elemType elem, compare cmp, int* agrego)
{
    int c;
    if (lista == NULL || (c=cmp(elem, lista->elem)<0))
    {
        Tlist aux = malloc(sizeof(Tnode));
        aux->elem = elem;
        aux->tail = lista;
        *agrego=1;
        return aux;
    }
    else if (c > 0)
    {
        lista->tail = addRec(lista->tail, elem, cmp, agrego);
    }
    return lista;
}
int add (setADT set, elemType elem)
{
    int agrego=0;
    set->first = addRec(set->first, elem, set->cmp, &agrego);
    if (set->size == 0)
    {
        set->max = elem;
        set->min = elem;
    }
    set->size+=agrego;
    if (agrego)
    {
        set->last = elem;
        if (set->cmp(elem, set->max)>0)
        {
            set->max = elem;
        }
        if (set->cmp(elem, set->min)<0)
        {
            set->min = elem;
        }
    }
    return set->size;
}


//Retorna cuantos elementos hay en el conjunto
int size (const setADT set)
{
    return set->size;
}


//Retorna una copia del mayor elemento del conjunto, NULL si no hay elementos
elemType * max (const setADT set)
{
    elemType* aux = malloc(sizeof(elemType));
    *aux = set->max;
    return aux;
}


//Retorna una copia del menor elemento del conjunto, NULL si no hay elementos
elemType * min (const setADT set)
{
    elemType* aux = malloc(sizeof(elemType));
    *aux = set->min;
    return aux;
}


//Retorna una copia del ultimo elemento agregado en el conjunto, NULL si estÃ¡ vacio
elemType * last (const setADT set)
{
    elemType* aux = malloc(sizeof(elemType));
    *aux = set->last;
    return aux;
}


//Retorna un vector con todos los elementos del conjunto, ordenados en forma ascendente
elemType * setToArray (const setADT set)
{
    elemType* vec = malloc(set->size * sizeof(elemType));
    Tlist aux = set->first;
    int auxdim = set->size;

    for (int i = 0; i < auxdim; i++)
    {
        vec[i] = aux->elem;
        aux = aux->tail;
    }
    return vec;
}

static int comparex (elemType e1, elemType e2){
    return e1-e2;
}

int main (void){
    setADT mySet=newSet(comparex);

    int v[]={1,2,3,4,5,6,7,8,9,10};

    assert(size(mySet)==0);

    for (size_t i = 0; i < 10 ; i++){
        assert(add( mySet ,v[i] )== (i+1));
    }
    int * auxMax, * auxMin, * auxLast;
    auxMax = max(mySet);
    auxLast = last(mySet);
    auxMin = min(mySet);
    
    assert(*auxMax==10 && *auxLast==10);
    assert(*auxMin==1);
    assert(size(mySet)==10);
    free(auxMax);
    free(auxMin);
    free(auxLast);

    for (size_t i = 0; i < 10 ; i++){
        assert(add( mySet ,v[i]) == (10));
    }

    add(mySet, 25);
    auxMax = max(mySet);
    assert(*auxMax==25);
    free(auxMax);

    int *w=setToArray(mySet);
    size_t i;

    for ( i = 0; i < 10 ; i++)    {
        assert(v[i]==w[i]);
    }
    assert( 25==w[i]);

    puts("Legendary!!!");

    return 0;
}