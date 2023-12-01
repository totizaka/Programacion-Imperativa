#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int producto(int x, int y) {
    return x * y;
}
 
int suma(int x, int y) {
    return x + y;
}

int operatoria(int vec[], int dim, int base, int(*f)(int, int))
{
    if (dim == 0)
    {
        return base;
    }
    return (*f) (*vec, operatoria(vec+1, dim-1, base, f));
}

int
main(void) {
    int v1[] = {2,3,4,5};
    assert(operatoria(v1, 4, 1, producto) == 120);
    assert(operatoria(v1, 4, 0, suma) == 14);
 
    printf("OK!\n");
    return 0;
}