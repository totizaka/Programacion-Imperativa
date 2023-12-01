#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Parciales/parciales/2p2022/eje2.h"

#define CANT_LIBROS 76

typedef struct versiculos
{
    char** versiculo;
    int cantVers;
}Tversiculos;

typedef struct bibleCDT
{
    Tversiculos libro[CANT_LIBROS];
}bibleCDT;

bibleADT newBible()
{
    bibleADT nuevo = calloc(1, sizeof(bibleCDT));
    return nuevo;
}

/*
** Agrega un versículo a la Biblia. Si ya estaba ese número de versículo en ese
** número de libro, no lo agrega ni modifica y retorna 0. Si lo agregó retorna 1
** bookNbr: número de libro
** verseNbr: número de versículo
*/
#define BLOQUE 5
int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse)
{
    if (bookNbr > CANT_LIBROS)
    {
        return 0;
    }
    if (bible->libro[bookNbr-1].cantVers == 0)
    {
        bible->libro[bookNbr-1].versiculo = calloc((verseNbr+1), sizeof(Tversiculos));
        bible->libro[bookNbr-1].cantVers = verse;
    }
    if (bible->libro[bookNbr-1].cantVers < verseNbr)
    {
        bible->libro[bookNbr-1].versiculo = realloc(bible->libro[bookNbr-1].versiculo, (verseNbr+1) * sizeof(Tversiculos));
        for (int i = bible->libro[bookNbr-1].cantVers; i < verseNbr; i++)
        {
            bible->libro[bookNbr-1].versiculo[i] = NULL;
        }
        bible->libro[bookNbr-1].cantVers = verseNbr;
    }
    if (bible->libro[bookNbr-1].versiculo[verseNbr] != NULL)
    {
        return 0;
    }
    char* copy = NULL;
    int dim=0;
    for (; verse[dim] != '\0'; dim++)
    {
        if (dim % BLOQUE == 0)
        {
            copy = realloc(copy, (dim+BLOQUE) * sizeof(char));
        }
        copy[dim] = verse[dim];
    }
    copy = realloc(copy, (dim+1)*sizeof(char));
    copy[dim] = '\0';

    bible->libro[bookNbr-1].versiculo[verseNbr-1] = copy;
    
    return 1;
}

/*
** Retorna una copia de un versículo o NULL si no existe.
** bookNbr: número de libro
** verseNbr: número de versículo
*/
char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr)
{
    char* retver=NULL;
    int dimver=0;

    if (bookNbr > CANT_LIBROS || bookNbr == 0 || verseNbr > bible->libro[bookNbr-1].cantVers)
    {
        return NULL;
    }
    while (bible->libro[bookNbr-1].versiculo[verseNbr-1] != '\0')
    {
        if (dimver%BLOQUE == 0)
        {
            retver = realloc(retver, (dimver+BLOQUE)*sizeof(char));
        }
        retver[dimver] = bible->libro[bookNbr-1].versiculo[verseNbr-1][dimver];
        dimver++;
    }
    retver = realloc(retver, (dimver+1)*sizeof(char));
    retver[dimver]='\0';
    return retver;
}

/* Libera todos los recursos reservados por el TAD */
void freeBible(bibleADT bible)
{
    for (int i=0; i < CANT_LIBROS; i++)
    {
        for (int j = 0; j < bible->libro[i].cantVers; j++)
        {
            free(bible->libro[i].versiculo[j]);
        }
        free(bible->libro[i].versiculo);
    }
    free(bible);
}