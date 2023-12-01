#include <stdio.h>
#include <stdlib.h>

int contarGrupos(char* string, char c)
{
    if (*string == '\0')
    {
        return 0;
    }
    if (*(string+1) == '\0')
    {
        return *string == c;
    }
    int aux = contarGrupos(string+1, c);

    if (*string == c && *(string+1)!= c)
    {
        aux++;
    }
    return aux;
}