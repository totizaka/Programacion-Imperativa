#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ramas(int h, int min)
{
    if (h < min)
    {
        return 0;
    }
    return 1+(2 * ramas(h/2, min));
}
