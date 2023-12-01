#include <stdio.h>

    // int interseccion(int vec1[], int vec2[], int dim1, int dim2, int resp[]){

    // int aux, r=0;

    // for (int i = 0; i < dim1; i++)
    // {
    //     aux = vec1[i];

    //     for (int j = 0; i < dim2; i++)
    //     {
    //         if (vec2[j]==aux)
    //         {
    //             resp[r]=aux;
    //             r++;
    //         }   
    //     }   
    // }
    // return r;
    // }



int interseccion(int vec1[], int vec2[], int dim1, int dim2, int resp[]){

int it2=0, r=0;

for (int it1 = 0; it1 < dim1 && it2 < dim2;)
{
    if (vec1[it1]<vec1[it2])
    {
        it1++;
    }
    else if (vec1[it1]==vec2[it2])
    {
        resp[r++]=vec1[it1];
        it1++;
        it2++;
    }
    else if (vec1[it1]>vec2[it2])
    {
        it2++;
    }
}
return r;

}