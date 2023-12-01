#include <stdio.h>
#include <stdlib.h>

int suma(int* vec, int dim)
{
    if (dim == 0)
    {
        return 0;
    }
    return (vec[dim-1] + suma(vec, dim-1));
}

int main()
{
    int vec[4] = {1,3,5,4};

    int sumax = suma(vec, 4);

    printf("%d", sumax);
}