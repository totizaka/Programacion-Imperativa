#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../Biblioteca/random.h"
#include "../Parciales/parciales/parcial2016/eje3.h"

typedef struct palabra
{
    char** palabra;
    size_t cant;
}Tpalabras;

typedef struct hangmanCDT
{
    Tpalabras* nivel;
    size_t cantNiv;
}hangmanCDT;


/* Crea la estructura que dara el soporte al almacenamiento y seleccion de palabras
** maxLevel: la cantidad maxima de niveles de dificultad que soportara (como minimo 1)
*/
hangmanADT newHangman(unsigned int maxLevel)
{
    hangmanADT nuevo = malloc(sizeof(hangmanCDT));
    nuevo->nivel = calloc(maxLevel, sizeof(Tpalabras));
    nuevo->cantNiv = maxLevel;
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
    if (level > h->cantNiv || level == 0)
    {
        return -1;
    }
    int existe=0;
    int agregadas=0;
    for (int j = 0; words[j] != '\0'; j++)
    {
        for (int i = 0; i < h->nivel[level-1].cant; i++)
        {
            if (strcmp(words[j], h->nivel[level-1].palabra[i]))
            {
                existe=1;
            }
        }
        if (!existe)
        {   
            h->nivel[level-1].cant+=1;
            h->nivel[level-1].palabra = realloc(h->nivel[level-1].palabra, h->nivel[level-1].cant * sizeof(char*));
            h->nivel[level-1].palabra[h->nivel[level-1].cant-1] = words[j];
            agregadas+=1;
        }
    }
    return agregadas;
}


/* Retorna cuantas palabras hay en un nivel, -1 si el nivel es invalido */
int size(const hangmanADT h, unsigned int level)
{
    return h->nivel[level-1].cant;
}

/* Retorna una palabra al azar de un nivel determinado, NULL si no hay palabras de ese nivel
** o si el nivel es invalido.
*/
char * word(const hangmanADT h, unsigned int level)
{
    // if (level == 0 || level > h->cantNiv || h->nivel[level-1].cant = 0)
    // {
    //     return NULL;
    // }
    int num = randInt(1, h->nivel[level-1].palabra[h->nivel[level-1].cant]);

    return h->nivel[level-1].palabra[num-1];
}

/* Retorna todas las palabras de un nivel, o NULL si el nivel es invalido
** El ultimo elemento del vector es el puntero NULL
*/
char ** words(const hangmanADT h, unsigned int level)
{
    if (level == 0 || level > h->cantNiv)
    {
        return NULL;
    }
    char** vec = malloc((h->nivel[level-1].cant+1) * sizeof(char*));
    int vecdim=0;

    for (; vecdim < h->nivel[level-1].cant; vecdim++)
    {
        vec[vecdim] = h->nivel[level-1].palabra[vecdim];
    }
    vec[vecdim] = NULL;
    return vec;
}