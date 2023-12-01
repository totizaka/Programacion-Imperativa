#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
// typedef int (*fnInt) (int);
void transforma(int v[], size_t dim, int (*f)(int));
static void assertArrayEquals(const int *, const int *, size_t);
 
int cuadrado(int x) {
    return x * x;
}

// Sólo para testing
static void
assertArrayEquals(const int * expected, const int * actual, size_t dim) {
    for(int i = 0; i < dim; i++) {
        assert(expected[i] == actual[i]);
    }
}

void transforma(int vec[], size_t n, int(*f)(int))
{
    if (n != 0)
    {
        *vec = (*f) (*vec);
        transforma(vec+1, n-1, f);
    }
    return;
}

int
main(void) {
    int v1[] = {2,3,4,5};
    transforma(v1, 4, cuadrado);
    int v1Expected[] = {4,9,16,25};
    assertArrayEquals(v1Expected, v1, 4);
 
    printf("OK!\n");
    return 0;
}