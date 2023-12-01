#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void piramide(int* latas, int* altura)
{
    if (*latas == 0)
    {
        return 0;
    }
    if (*latas >= (*altura + 1) * (*altura + 1))
    {
        (*altura)+=1;

        *latas -= *altura * *altura;

        piramide(latas, altura);
    }
}