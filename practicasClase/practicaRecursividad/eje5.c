#include <stdio.h>

int main()
{
    int vec[] = {0,0,0,0};

    printf("vec %s nulo/n", isNull(vec, 4) ? "es" : "no es");
}

int isNull(int vec[], int dim)
{
    if (dim == 0)
    {
        return 1;
    }
    return (vec[0] == 0 && isNull(vec+1, dim-1));
}