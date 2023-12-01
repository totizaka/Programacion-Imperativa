#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

/* Copiar el string a uno nuevo pasado a mayusculas */
char * pasaMayusculas(const char * s)
{
    char * aux;
    int i;

    if ((aux = malloc(strlen(s)+1)) == NULL)
        return NULL;

    for(i = 0; s[i] != 0; i++)
    {
        aux[i] = toupper(s[i]);
        aux[i] = 0;
    }
    return aux;
}

/* Copiar un vector a otro pero en forma invertida.
** Se recibe el vector original y la dimensión del mismo
*/
int * copiaVector (int v[], int dim)
{
    int * resp, i;
    resp = malloc( dim * sizeof(int));
    
    if (resp == NULL)
        return resp;

    for (i = dim; i > 0; i-- )
        resp[i] = v[dim - i];

    return resp;
}