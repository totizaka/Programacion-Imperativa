#include <stdio.h>
#include <stdlib.h>

void palotes(unsigned int cant)
{
    if (cant != 0)
    {
        putchar('|');
        palotes(cant-1);
    }
}

int strlens(char* string)
{
    if (*string != '\0')
    {
        return (1 + strlens(string+1));
    }
    return 0;
}

char* strchrs(char* string, char car)
{
    if (*string == '\0')
    {
        return NULL;
    }
    if (*string == car)
    {
        return string;
    }
    if (*string != car)
    {
        return (strchrs((string+1), car));
    }
}


int main()
{
    char* string = "chauls";

    char* nuevo = strchrs(string, 'u');

    printf("%s", nuevo);

    return 0;
}