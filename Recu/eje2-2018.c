#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Parciales/parciales/recu2018/eje2.h"

typedef int (*compare)(elemType, elemType);

typedef struct node{
    elemType elem;
    int cant;
    struct node* tail;
}Tnode;

typedef Tnode* Tlist;

typedef struct multiSetCDT{
    Tlist first;
    compare cmp;
    size_t size;
}multiSetCDT;

/* Retorna un nuevo multiSet de elementos genéricos. Al inicio está vacío */
multiSetADT newMultiSet(compare cmp)
{
    multiSetADT nuevo = calloc(1, sizeof(multiSetCDT));
    nuevo->cmp = cmp;
    return nuevo;
}

/* Inserta un elemento. Retorna cuántas veces está elem en el conjunto
** luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
Tlist addRec(Tlist list, elemType elem, compare cmp, int* agrego, int* apariciones)
{
    int c;
    if (list == NULL || (c=cmp(list->elem, elem))>0)
    {
        Tlist aux = malloc(sizeof(Tnode));
        aux->elem=elem;
        aux->tail=list;
        aux->cant=1;
        *agrego=1;
        *apariciones=1;
        return aux;
    }
    if (c == 0)
    {
        list->cant+=1;
        *apariciones = list->cant;
        return list;
    }
    list->tail = addRec(list->tail, elem, cmp, agrego, apariciones);
    return list;
}
unsigned int add(multiSetADT multiSet, elemType elem)
{
    int agrego=0;
    int apariciones=0;
    multiSet->first = addRec(multiSet->first, elem, multiSet->cmp, &agrego, &apariciones);
    multiSet->size+=agrego;
    return apariciones;
}

/* Retorna cuántas veces aparece el elemento en el multiSet */
unsigned int count(const multiSetADT multiSet, elemType elem)
{
    Tlist aux = multiSet->first;

    for (int i = 0; i < multiSet->size; i++)
    {
        if (aux->elem == elem)
        {
            return aux->cant;
        }
        aux = aux->tail;
    }
    return 0;
}

/* Retorna la cantidad de elementos distintos que hay en el multiSet */
unsigned int size(const multiSetADT multiSet)
{
    return multiSet->size;
}

/* Elimina una repetición del elemento. Retorna cuántas veces está elem el conjunto
** luego de haberlo borrado (si el elemento no estaba, retorna cero)
*/
Tlist removeOneRec(Tlist list, elemType elem, compare cmp, int* elimine, int* apariciones)
{   
    int c;
    if (list == NULL || (c=cmp(list->elem, elem))>0)
    {
        return list;
    }
    if (c == 0)
    {
        if (list->cant > 1)
        {
            list->cant-=1;
            *apariciones=list->cant;
            return list;
        }
        else
        {
            Tlist aux = list->tail;
            free(list);
            *elimine=1;
            *apariciones=0;
            return aux;
        }
    }
    list->tail = removeOneRec(list->tail, elem, cmp, elimine, apariciones);
    return list;
}
int removeOne(multiSetADT multiSet, elemType elem)
{
    int elimine=0;
    int apariciones=0;
    multiSet->first = removeOneRec(multiSet->first, elem, multiSet->cmp, &elimine, &apariciones);
    multiSet->size-=elimine;
    return apariciones;
}

/* Elimina todas las apariciones de un elemento. */
Tlist removeAllRec(Tlist list, elemType elem, compare cmp, int* elimine)
{
    int c;
    if (list == NULL || (c=cmp(list->elem, elem))>0)
    {
        return list;
    }
    if (c == 0)
    {
        *elimine=1;
        Tlist aux = list->tail;
        free(list);
        return aux;
    }
    list->tail = removeAllRec(list->tail, elem, cmp, elimine);
    return list;
}
void removeAll(multiSetADT multiSet, elemType elem)
{
    int elimine=0;
    multiSet->first = removeAllRec(multiSet->first, elem, multiSet->cmp, &elimine);
    multiSet->size-=elimine;
    return;
}


/* Retorna un vector con los elementos que menos aparecen en el conjunto
** Si el conjunto está vacío retorna NULL
** En el parámetro de salida dim almacena la cantidad de elementos del vector
*/
#define BLOQUE 5
elemType * minElements(const multiSetADT multiSet, int * dim)
{
    elemType* vec = malloc(BLOQUE * sizeof(Tnode));
    int dimvec=0;
    elemType min;
    Tlist aux = multiSet->first;

    for (int i = 0; i < multiSet->size; i++)
    {
        if (i == 0 || aux->cant < min)
        {
            dimvec=0;
            min=aux->cant;
            vec[dimvec++]=aux->elem;
        }
        else if (aux->cant == min)
        {   
            if (dimvec % BLOQUE == 0)
            {   
                vec = realloc(vec, (dimvec+BLOQUE)*sizeof(Tnode));
            }
            vec[dimvec++]=aux->elem;
        }
        aux=aux->tail;
    }
    vec[dimvec]='\0';
    vec = realloc(vec, dimvec*sizeof(Tnode));
    *dim = dimvec;
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
void freeMultiSet(multiSetADT multiSet)
{
    freeRec(multiSet->first);
    free(multiSet);
}

static int comparex ( elemType e1 , elemType e2 ){
    return e1-e2;
}

int main (void){
    multiSetADT mySet=newMultiSet(comparex);
    int v[]={1,2,3,4,5,6,7,8,9,10};

    for ( int i=0 ; i<10 ; i++ ){
        assert(add(mySet,v[i])==1);
    }
    assert(size(mySet)==10);
    printf("Cantalo\n");

    int x=11;
    for ( int i=0 ; i<10 ; i++ ){
        assert(add(mySet,x )==i+1);//agrego 10 veces x
    }
    printf("Cantalo\n");

    assert(size(mySet)==11);
    int aux=count(mySet,x);
    assert(aux==10);

    for ( int i=0 ; i<(aux) ; i++ ){
        assert(removeOne(mySet,x)==(aux-1-i));
    } 

    assert(size(mySet)==10);
    assert(removeOne(mySet,x)==0);
    assert(count(mySet,x)==0);

    printf("Cantalo\n");

    removeAll(mySet,1);

    assert(size(mySet)==9);
    assert(count(mySet,1)==0);

    //lista tiene 2,3,4,5,6,7,8,9,10
    

    add(mySet,2);
    add(mySet,2);//2 tiene 3

    printf("Cantalo\n");

    add(mySet,3);
    add(mySet,3);
    add(mySet,3);//3 tiene 4

    add(mySet,4);//4 tiene 2
    
    //5,6 tiene 1

    add(mySet,7);
    add(mySet,7);//7 tiene 3

    //8,9 tiene 1
    add(mySet,10);//10 tiene 2
    add(mySet,-1);
    add(mySet,13);

    printf("Cantalo\n");

    int dim;
    int *w=minElements(mySet,&dim);
    assert(dim==6);

   /* int expectedList[]={-1,5,6,8,9,13};//para listas, porque esta ordenado ascendente
    for (size_t i = 0; i < dim; i++){
        assert(w[i]==expectedList[i]);
    }//hasta aca testlista*/

    int expectedVec[]={5,6,8,9,-1,13};//para vec (no ordenado)}
    int flagsVec[6]={0};
    int flag;
    for (size_t i=0; i < dim ; i++){
        flag=1;
        for ( size_t j=0 ; j<dim && flag ;j++){
            if ( w[i]==expectedVec[j] ){
                flagsVec[i]=1;
                flag=0;
            }
        }
    }

    for (size_t i = 0; i < dim; i++){
        assert(flagsVec[i]);   
    }
    //como no se sabe en que orden pueden salir del vector, unicamente revisamos que esten

    //es el unico test que queda diferente por si se plantea con vec o con TList
    
    free(w);
    freeMultiSet(mySet);

    printf("GOOOOLLLLL\n");

}