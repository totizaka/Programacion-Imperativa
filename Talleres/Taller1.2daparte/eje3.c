#include <stdio.h>
#include <stdlib.h>
#include "../Getnum/getnum.h"

#define TAM 10

int main()
{
    int car, dim=0;
    char *vec = NULL;

        do{
            car = getchar();
            if (dim % TAM == 0)
            {
                vec = realloc(vec, (dim + TAM) * sizeof(char));
            }
            if (car != EOF)
            {
                vec[dim++]=car;
            }
        }
        while (car != EOF );

        vec = realloc(vec, dim*sizeof(char));

    for (int i=0; i<dim; i++)
    {   printf("%c", vec[i]);
    }
        free(vec);

    return 0;
}