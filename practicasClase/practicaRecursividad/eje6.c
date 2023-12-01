#include <stdio.h>

int esvocal(char car)
{
    if (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u')
    {
        return 1;
    }
    return 0;
}

int cantVocal(char *s)
{
    if(*s == '\0')
    {
        return 0;
    }
    return(esvocal(*s) + cantVocal(s+1));
}

int main()
{
    char *s="aeiou";

    int cant = cantVocal(s);

    printf("%d", cant);
}