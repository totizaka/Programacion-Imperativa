#include <stdio.h>

int eliminarRepetidos(int vec[], int dim, int resp[]){

int dim2=0;

if (vec[0]!=vec[1])
{
    resp[0]=vec[0];
    dim2++;
}

for ( int it1 = 1; it1 < dim-1; it1++ )
{  
    if (vec[it1]!=vec[it1 -1])
    {
        resp[dim2]=vec[it1];
    }
}

return dim2;

}