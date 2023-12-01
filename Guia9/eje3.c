#include <stdio.h>
#include <stdlib.h>

int prodcutoEsc(int* vec1, int* vec2, int dim)
{
    if (dim == 0)
    {
        return 0;
    }
    return (vec1[dim-1] * vec2[dim-1]) + prodcutoEsc(vec1, vec2, dim-1);
}

int main()
{
    int vec[4] = {1,3,-5,4};
    int vec2[4] = {2,1,2,2};

    int porducto = prodcutoEsc(vec, vec2, 4);

    printf("%d", porducto);
}