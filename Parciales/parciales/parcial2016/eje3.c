#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
#include "eje3.h"
#include <string.h>
#include"PI/Biblioteca/random.h"

typedef struct nivel
{
    char** palabras;
    size_t cantPalabras;

}Tnivel;

typedef struct hangmanCDT
{
    Tnivel* nivel;
    size_t cantNiveles; 
}hangmanCDT;


/* Crea la estructura que dara el soporte al almacenamiento y seleccion de palabras
** maxLevel: la cantidad maxima de niveles de dificultad que soportara (como minimo 1)
*/
hangmanADT newHangman(unsigned int maxLevel)
{   
    if (maxLevel <= 0)
    {
        return NULL;
    }
    srand(time(NULL));
    hangmanADT nuevo = malloc(sizeof(hangmanCDT));
    nuevo->nivel = calloc(maxLevel, sizeof(Tnivel));
    nuevo->cantNiveles = maxLevel;
    return nuevo;
}


/* Agrega un conjunto de palabras asociadas a un nivel de dificultad.
** El arreglo words[] esta finalizado en NULL
** Si alguna de las palabras words[] ya existe en el hangmanADT para ese nivel de dificultad
** se ignora.
** No se realiza una copia local de cada palabra sino unicamente los punteros recibidos
** Si el nivel supera la cantidad maxima definida en newHangman, se ignora y retorna -1
** Retorna cuantas palabras se agregaron al nivel
*/
int addWords(hangmanADT h, char* words[], unsigned int level)
{   
    int agregadas=0;
    int existe=0;
    if (level > h->cantNiveles)
    {
        return -1;
    }
    for (int i = 0; words[i] != NULL; i++)
    {
        for (int j = 0; j < h->nivel[level-1].cantPalabras; j++)
        {
            if (strcmp(words[i], h->nivel[level-1].palabras[j])==0)
            {
                existe=1;
            }
        }
        if (!existe)
        {
            h->nivel[level-1].cantPalabras+=1;
            h->nivel[level-1].palabras = realloc(h->nivel[level-1].palabras, h->nivel[level-1].cantPalabras * sizeof(char*));
            h->nivel[level-1].palabras[h->nivel[level-1].cantPalabras-1]  = words[i];
            agregadas++;
        }
    }
    return agregadas;
}

/* Retorna cuantas palabras hay un nivel, -1 si el nivel es invalido */
int size(const hangmanADT h, unsigned int level)
{
    if (level > h->cantNiveles  || level == 0)
    {
        return -1;
    }
    return h->nivel[level-1].cantPalabras;
}


/* Retorna una palabra al azar de un nivel determinado, NULL si no hay palabras de ese nivel
** o si el nivel es invalido.
*/
char * word(const hangmanADT h, unsigned int level)
{
    if (level > h->cantNiveles || level == 0 || h->nivel[level-1].cantPalabras == 0)
    {
        return NULL;
    }
    int i = randInt(0, h->nivel[level-1].cantPalabras-1);
    return h->nivel[level-1].palabras[i];
}


/* Retorna todas las palabras de un nivel, o NULL si el nivel es invalido
** El ultimo elemento del vector es el puntero NULL
*/
char ** words(const hangmanADT h, unsigned int level)
{
    if (level > h->cantNiveles || level <= 0 || h->nivel[level-1].cantPalabras == 0)
    {
        return NULL;
    }
    char** words = malloc(h->nivel[level-1].cantPalabras * sizeof(char*));
    int i;
    for ( i = 0; i < h->nivel[level-1].cantPalabras; i++)
    {
        words[i] = h->nivel[level-1].palabras[i];
    }
    words[i] = NULL;

    return words;
}