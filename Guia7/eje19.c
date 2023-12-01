#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

char* copiaPrefijo(char* s, int n)
{
    int i;
    char* aux;

    if ((aux = malloc(n*sizeof(char) +1)) == NULL)
    {
        return NULL;
    }

    for (i = 0; i < n && s[i]!=0; i++)
    {
        aux[i] = s[i];
    }
    aux[i]=0;
    
    return aux;
}