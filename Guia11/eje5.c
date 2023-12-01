#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/utillist.h"
#include <assert.h>

typedef int typeElem;

typedef struct ComplejoCDT{
    float real;
    float im;
}ComplejoCDT;

typedef ComplejoCDT* complejoADT;

complejoADT nuevoComp(float real, float im)
{
    complejoADT nuevo = malloc(sizeof(ComplejoCDT));
    nuevo->real = real;
    nuevo->im = im;
    return nuevo;
}

typeElem  parteRealComp(complejoADT num)
{   
    return num->real;
}

typeElem parteImagComp(complejoADT num)
{
    return num->im;
}

complejoADT sumaComp(complejoADT num1, complejoADT num2)
{
    complejoADT nuevo = nuevoComp(num1->real + num2->real, num1->im + num2->im);

    return nuevo;
}

void liberaComp(complejoADT num)
{
    free(num);
}

#define EPS 0.01

int main(void) {
  complejoADT comp1 = nuevoComp( 1, 2 ); // comp1 = 1 + 2i
	complejoADT comp2 = nuevoComp( 2, -3 ); // comp2 = 2 - 3i
	complejoADT ans;

	ans = sumaComp( comp1, comp2 );
	assert( parteRealComp(ans) - 3 < EPS && parteImagComp(ans) + 1 < EPS );
	liberaComp( ans );

	// ans = restaComp( comp1, comp2 );
	// assert( parteRealComp(ans) - 1 < EPS && parteImagComp(ans) - 5 < EPS );	
	// liberaComp( ans );

	// ans = multiplicaComp( comp1, comp2 );
	// assert( parteRealComp(ans) - 8 < EPS && parteImagComp(ans) - 1 < EPS );
	// liberaComp( ans );

	// ans = divideComp( comp1, comp2 );
	// assert( parteRealComp(ans) + 0.31 < EPS && parteImagComp(ans) - 0.54 < EPS );
	// liberaComp( ans );

	// ans = conjugadoComp( comp1 );
	// assert( parteRealComp(ans) - 1 < EPS && parteImagComp(ans) + 2 < EPS );

	liberaComp( comp1 );
	liberaComp( comp2 );
	// liberaComp( ans );

	printf("OK!\n");
}