#include <stdio.h>
#include "../Biblioteca/getnum.h"
#include <math.h>

#define DIM 50

int readArray(double v[]){

int i=0;

float num;

while (i<DIM && (num = getfloat("")>0))
{
    v[i++]=num;
}
    return i;
}


