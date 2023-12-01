#include <stdio.h>
#include <stdlib.h>
#include "eje2-2017.h"

typedef struct node{
    elemType clave;
    elemType valor;
    struct node* tail;
}Tnode;

typedef Tnode* Tclave;

typedef struct dictCDT{
    Tclave first;
    size_t cant;
    compare cmp;
}dictCDT;

/*
** Crea un nuevo diccionario para asociar pares de clave / valor. 
** Inicialmente está vacío.
** Se inserta una copiatanto de la clave como del valor
*/
dictADT newDict(compare cmp)
{
    dictADT nuevo = calloc(1, sizeof(dictCDT));
    nuevo->cmp = cmp;
    return nuevo;
}


/*
** Agrega un elemento al diccionario. Si key o value son NULL, no los agrega
**  key: clave. Se inserta una COPIA de la clave recibida
**  value: valor asociado a la clave. Se inserta una COPIA del valor recibido
** Si ya existía la clave, el valor se pisa con value (se lo considera una actualización) 
*/
Tclave addRec(Tclave list, compare cmp, elemType* key, elemType* value)
{
    int c;
    if (list == NULL || (c=cmp(key, list->clave))<0)
    {
        Tclave aux = malloc(sizeof(Tnode));
        aux->clave = *key;
        aux->valor = *value;
        aux->tail = list;
        return aux;
    }
    else if (c > 0)
    {
        list->tail = addRec(list->tail, cmp, key, value);
    }
    list->valor = *value;
    return list;
    
}
void addkey (dictADT dic, const elemType * key, const elemType * value)
{
    if (key == NULL || value == NULL)
    {
        return;
    }
    dic->first = addRec(dic->first, dic->cmp, key, value);
    return;
}

/*
** Retorna una copia del valor asociado a key o NULL si no estaba la clave
** en el diccionario 
*/
elemType* getValue (dictADT dic, const elemType * key)
{
    Tclave aux = dic->first;
    int esta=0;
    elemType* valret;
    for (int i = 0; i < dic->cant; i++)
    {
        if (aux->clave == *key)
        {
            valret = malloc(sizeof(elemType));
            *valret = aux->valor;
            esta=1;
        }
        aux = aux->tail;
    }
    if (esta)
    {
        return valret;
    }
    return NULL;
}

/*
** Vector que contenga una copia de todas las claves
** Cada elemento del vector es una COPIA de las claves en el diccionario
** El vector debe finalizar en NULL
** Si no hay claves (el diccionario está vacío) retorna un vector que sólo contiene NULL
*/
#define BLOQUE 5

elemType ** keys (dictADT dic)
{
    if (dic->cant == 0)
    {
        return NULL;
    }
    elemType** vecret = malloc((dic->cant+1) * sizeof(elemType*));
    int dimvec=0;
    Tclave aux = dic->first;
    for (; dimvec < dic->cant; dimvec++)
    {
        elemType* copykey = malloc(sizeof(elemType));
        *copykey = aux->clave;
        vecret[dimvec] = *copykey;
        aux = aux->tail;
    }
    return vecret;
}