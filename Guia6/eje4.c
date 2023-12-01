#include <stdio.h>

int eliminarRepetidos(int vec[], int dim, int resp[] /*, int num*/){

int dim2=0;

for ( int it1 = 0; it1 < dim; it1++ )
{
    int contador=0;

    for ( int it2 = 0; it2 < dim && contador < 2; it2++)
    {
        if (vec[it1]==vec[it2])
        {
            contador++;
        }
    }
    
    if (contador<2)
    {
        resp[dim2]=vec[it1];

        dim2++;
    }
}

return dim2; //resp[num];

}

int main(){

int vec[8]={5,3,4,5,5,5,8,9};

int resp[8];

printf("\n%d", eliminarRepetidos(vec, 8, resp));

// for (int i = 0; i < 8; i++)
// {
//     printf("\n%d", eliminarRepetidos(vec, 8, resp, i));
// }


    return 0;
}