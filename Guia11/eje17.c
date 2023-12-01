#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
#include "eje17.h"
#include <string.h>

#define BLOQUE 10

typedef struct frase
{
    char* frase;
    size_t longitud;
}Tfrase;

typedef struct phrasesCDT
{
    Tfrase* frases;
    size_t cant;
    size_t tope;
    size_t min;
}phrasesCDT;


/*
* Recibe cuál será el rango de claves válidas a utilizar, por ejemplo si
* keyFrom=1001, keyTo=1500 habrá un máximo de 500 frases a almacenar
* keyFrom=1001, keyTo=3500 habrá un máximo de 2500 frases a almacenar
* Si los parámetros son inválidos retorna NULL
*/
phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo)
{
    if (keyTo < keyFrom)
    {
        return NULL;
    }
    phrasesADT nuevo = malloc(sizeof(phrasesCDT));
    nuevo->tope = keyTo;
    nuevo->min = keyFrom;
    nuevo->frases = calloc(keyTo-keyFrom+1, sizeof(Tfrase)); 
    return nuevo;
}

void freePhrases(phrasesADT lista)
{
    for (int i = 0; i < lista->tope - lista->min+1; i++)
    {
        free(lista->frases[i].frase);
    }
    free(lista->frases);
    free(lista);
}


/*
* Agrega una frase. Si la clave key es inválida retorna 0, sinó retorna 1 (uno)
* Si ya hay una frase asociada a la clave, actualiza la frase almacenada,
* reemplazándola por el parámetro phrase.
* Se almacena una copia de la frase.
*/
char* copiar(char* phrase, size_t* largo)
{
    char* copia=NULL;
    size_t dim = 0;
    while (phrase[dim] != '\0')
    {
        if (dim % BLOQUE == 0)
        {
            copia = realloc(copia, (BLOQUE+dim)*sizeof(char));
        }
        copia[dim]=phrase[dim];
        dim++;
        *largo+=1;
    }
    copia = realloc(copia, (dim+1)*sizeof(char));
    copia[dim]='\0';
    return copia;
}
int put(phrasesADT lista, size_t key, const char * phrase)
{
    if (key < lista->min || key > lista->tope)
    {
        return 0;
    }
    size_t largo=0;
    char* copia = copiar(phrase, &largo);

    size_t posicion = (key - lista->min);
    lista->frases[posicion].frase = copia;
    lista->frases[posicion].longitud = largo;
    lista->cant+=1;
    return 1;
}


/*
* Retorna una copia de la frase asociada a la clave key. Si no hay frase asociada
* a la clave key retorna NULL, lo mismo si la clave es inválida.
*/
char * get(const phrasesADT lista, size_t key)
{
    if (key < lista->min ||  key > lista->tope)
    {
        return NULL;
    }
    size_t posicion = (key - lista->min);
    size_t largo = 0;
    if (lista->frases[posicion].frase != NULL)
    {
        char* copia = copiar(lista->frases[posicion].frase, &largo);
        return copia;
    }
    return NULL;
}


/*
* Cantidad de frases almacenadas
*/
size_t size(const phrasesADT lista)
{
    return lista->cant;
}


/*
* Retorna un string con todas las frases concatenadas 
* Si no hay frases retorna un string vacío
*/
char* copiarConcat(Tfrase* lista, size_t incio, size_t final)
{
    char* concatenado = NULL;

    unsigned int espacio=0;

    for (size_t i = incio; i < final; i++)
    {
        if (lista->longitud != 0)
        {
            concatenado = realloc(concatenado,espacio + lista[i].longitud+1);
            strcpy(concatenado+espacio, lista[i].frase);
            espacio += lista[i].longitud;
        }
    }
    return concatenado;
}
char* concatAll(const phrasesADT lista)
{   
    char* concatenado = NULL;
    if (lista->cant > 0)
    {
        concatenado = copiarConcat(lista->frases, 0, lista->tope - lista->min + 1);
    }
    return concatenado;
}


/*
* Retorna un string con todas las frases concatenadas cuyas claves estén entre
* from y to inclusive. Si from o to son inválidas (están fuera del rango)
* retorna NULL
* Si no hay frases en ese rango, retorna un string vacío
*/
char * concat(const phrasesADT lista, size_t from, size_t to)
{
    char* concatenado = NULL;
    if (from < lista->min || to > lista->tope || from > to)
    {
        return NULL;
    }
    if (lista->cant > 0)
    {
        concatenado = copiarConcat(lista->frases, from - lista->min, to - lista->min);
    }
    return concatenado;
}