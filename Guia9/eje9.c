#include <stdio.h>
#include <stdlib.h>

float raizNR(float valorAnterior, int iter, float x)
{
    float valorAprocimado;
    if (iter == 0)
    {
        return;
    }
    valorAprocimado = (valorAnterior + (x/valorAnterior))/2;
    return raizNR(valorAprocimado, iter-1, x);
}

#include <assert.h>
#include <math.h>

#define EPSILON 0.01

int main(void){

    assert(fabs(raizNR(4, 3, 8)-2.833) <= EPSILON);
    assert(raizNR(0, 0, 0) <= EPSILON);
    assert(raizNR(0, 0, 4) <= EPSILON);
    
    printf("OK!\n");
}