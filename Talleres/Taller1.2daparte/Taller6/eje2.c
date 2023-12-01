#include <stdio.h>
#include <math.h>
#include <assert.h>
 
#define EPSILON 0.000001

int solucionCuadratica( int a, int b, int c, float *r1, float *r2){

float discriminante = ((b*b)+(-4*a*c));

float cuadratica = ((-1*b) + (sqrt(discriminante)/(2*a)));

    if (discriminante < 0)
    {
        return 0;
    }
    else if (discriminante == 0)
    {
        *r1 = cuadratica;

        *r2 = *r1;

        return 1;
    }
    else
    {   
        *r1 = cuadratica;

        *r2 = ((-1*b) + (sqrt(discriminante)/(2*a)));

        return 2;
    }
}

int
main(void) {
    float r1, r2;
    assert(solucionCuadratica(1, -2, 1, &r1, &r2) == 1); // x^2 - 2x + 1
    assert(fabs(r1 - 1.0) < EPSILON);
    assert(fabs(r2 - 1.0) < EPSILON);
 
    assert(solucionCuadratica(2, 1, 0, &r1, &r2) == 2); // 2 x^2 + x
    assert(fabs(r1 - 0.0) < EPSILON); // Podria ser r1 = -0.5 y r2 = 0
    assert(fabs(r2 - -0.5) < EPSILON);
 
    assert(solucionCuadratica(1, 0, 1, &r1, &r2) == 0); // x^2 + 1
 
    printf("\nOK!\n");
    return 0;
}