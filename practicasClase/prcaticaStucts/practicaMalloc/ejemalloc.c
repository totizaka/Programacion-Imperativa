#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../Getnum/getnum.h"

float* leearreglo(int *n){

int dim;
float num;

do{
    dim = getint("ingresar cant de numeros");}
    while(dim<1);

float * resp = malloc(dim * sizeof(float));

for (int i=0; i < dim; i++)
{
    num = getfloat("ingresar numero real");
    
    *(resp+i) = num;
}

*n = dim;

return resp;

}


int main(){

float *vec;
int dim;

vec = leearreglo(&dim);

for (int i = 0; i < dim; i++)
{
    printf("%.2f\n", vec[i]);
}

free(vec);

    return 0;
}