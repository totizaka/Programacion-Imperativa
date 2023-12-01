#include <stdio.h>
#include <string.h>
#include <ctype.h>

int eliminacar(char *string)
{
    int longitud=0;

    for (int i = 0; *(string+i) != 0; i++)
    {
        if (isalpha(*(string+i)))
        {
            *(string+longitud) = *(string+i);
            longitud++;
        }
    }

    *(string+longitud) = '\0';

    return longitud;
}