#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int capicuaRec(const char* s, int dim)
{
    if (dim <= 1)
    {
        return 1;
    }
    
    return (s[0] == s[dim - 1] && capicuaRec(s+1, dim-2));
}