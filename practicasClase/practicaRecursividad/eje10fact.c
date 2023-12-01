#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void factorial(int n, int* resp)
{
    if (n <= 1)
    {
        *resp = 1;
    }
    else
    {
        (factorial(n-1, resp));

        *resp *= n;
    }
}