#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Parciales/parciales/parcial2016/eje2.h"

typedef int (*compare)(elemType, elemType);

typedef struct node
{
    int elem;
    struct node* tail;
}Tnode;

typedef Tnode* Tlist;

typedef struct setCDT
{
    Tlist first;
    elemType min;
    elemType max;
    elemType last;
    compare cmp;
    size_t size;
}setCDT;


//Retorna un nuveo conjunto de elementos genericos. Al principio estÃ¡ vacio
setADT newSet(compare cmp)
{
    setADT nuevo = calloc(1, sizeof(setCDT));
    nuevo->cmp = cmp;
    return nuevo;
}

//Inserta una copia superficial de elem siempre y cunado el elemento no estÃ© en el conjunto. 
//Retorna la cantidad total de elementos luego de agregar el elemento nuevo
Tlist addRec(Tlist list, elemType elem, compare cmp, int* agrego)
{
    int c;
    if (list == NULL || (c=cmp(list->elem, elem))>0)
    {
        Tlist aux = malloc(sizeof(Tnode));
        aux->elem = elem;
        aux->tail = list;
        *agrego=1;
        return aux;
    }
    else if (c < 0)
    {
        list->tail = addRec(list->tail, elem, cmp, agrego);
    }
    return list;
}
int add (setADT set, elemType elem)
{
    int agrego=0;
    set->first = addRec(set->first, elem, set->cmp, &agrego);
    if (agrego)
    {
        if (set->size == 0)
        {
            set->max = elem;
            set->min = elem;
            set->last = elem;
        }
        if (elem > set->max)
        {
            set->max = elem;
        }
        if (elem < set->min)
        {
            set->min = elem;
        }
        set->last = elem;
        set->size+=agrego;
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
    elemType* maxret = malloc(sizeof(elemType));
    *maxret = set->max;
    return maxret;
}

//Retorna una copia del menor elemento del conjunto, NULL si no hay elementos
elemType * min (const setADT set)
{
    elemType* minret = malloc(sizeof(elemType));
    *minret = set->min;
    return minret;
}

//Retorna una copia del ultimo elemento agregado en el conjunto, NULL si estÃ¡ vacio
elemType * last (const setADT set)
{
    elemType* lastret = malloc(sizeof(elemType));
    *lastret = set->last;
    return lastret;
}

#define BLOQUE 5
//Retorna un vector con todos los elementos del conjunto, ordenados en forma ascendente
elemType * setToArray (const setADT set)
{
    elemType* vec = NULL;
    int dimvec=0;
    Tlist aux = set->first;

    for (; dimvec < set->size; dimvec++)
    {
        if (dimvec % BLOQUE == 0)
        {
            vec = realloc(vec, (dimvec+BLOQUE)*sizeof(elemType));
        }
        vec[dimvec] = aux->elem;
        aux = aux->tail;
    }
    vec = realloc(vec, dimvec * sizeof(elemType));
    return vec;
}

void freeRec(Tlist list)
{
    if (list == NULL)
    {
        return;
    }
    Tlist aux = list->tail;
    free(list);
    freeRec(aux);
}
void freeSet(setADT set)
{
    freeRec(set->first);
    free(set);
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