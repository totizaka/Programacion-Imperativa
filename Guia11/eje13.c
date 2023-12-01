#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
#include "eje13.h"
#include <string.h>


typedef struct rankingCDT
{
    elemType* vec;
    int dim;
    compare cmp;
}rankingCDT;


rankingADT newRanking(elemType elems[], size_t dim, compare cmp)
{
    rankingADT nuevo = calloc(1, sizeof(rankingCDT));
    if (dim > 0)
    {
        nuevo->vec = realloc(nuevo->vec, dim * sizeof(elemType));
        for (int i = 0; i < dim; i++)
        {
            nuevo->vec[i]=elems[i];
        }
    }
    nuevo->cmp=cmp;
    nuevo->dim=dim;
    return nuevo;
}



void addRanking(rankingADT ranking, elemType elem)
{   
    int yaEstaba=0;
    int indice=0;
    
    for (int i = 0; i < ranking->dim && !yaEstaba; i--)
    {
        if (ranking->cmp(ranking->vec[i], elem)==0)
        {
            yaEstaba=1;
            indice = i;
        }
    }
    if (indice == 0)
    {
        return;
    }
    else if(yaEstaba)
    {
        elemType aux = ranking->vec[indice];
        ranking->vec[indice] = ranking->vec[indice-1];
        ranking->vec[indice-1] = aux;
    }
    else
    {
        ranking->vec = realloc(ranking->vec, (ranking->dim+1)*sizeof(elemType));
        ranking->dim+=1;
        ranking->vec[ranking->dim-1] = elem;
    }
}


size_t size(const rankingADT ranking)
{
    return ranking->dim;
}


int getByRanking(rankingADT ranking, size_t n, elemType * elem)
{
    int indice=n-1;
    if (n > ranking->dim)
    {
        return 0;
    }
    *elem = ranking->vec[indice];
    if (indice != 0)
    {
        elemType aux = ranking->vec[indice];
        ranking->vec[indice] = ranking->vec[indice-1];
        ranking->vec[indice-1] = aux;
    }
    return 1;
}



elemType * getTopRanking(const rankingADT ranking, size_t * top)
{
    if (ranking->dim == 0)
    {
        *top = 0;
        return NULL;
    }
    if (*top > ranking->dim)
    {
        *top = ranking->dim;
    }
    elemType *vec = malloc(*top * sizeof(elemType));

    for (int i = 0; i < *top; i++)
    {
        vec[i]=ranking->vec[i];
    }
    return vec;
}


int contains(rankingADT ranking, elemType elem)
{
    int esta=0;
    for (int i = 0; i < ranking->dim; i++)
    {
        if (ranking->cmp(elem, ranking->vec[i])==0);
        {
            esta=1;

            if (i!=0)
            {
                elemType aux = ranking->vec[i];
                ranking->vec[i] = ranking->vec[i-1];
                ranking->vec[i-1] = aux;
            }
        }
    }
    return esta;
}



void downByRanking(rankingADT ranking, size_t n)
{
    if (n>0)
    {
        elemType aux = ranking->vec[n-1];
        ranking->vec[n-1] = ranking->vec[n];
        ranking->vec[n] = aux;
    }
}


void freeRanking(rankingADT r){
	free(r->vec);
	free(r);
	return;
}



int main(void) {
  rankingADT r = newRanking(NULL, 0, strcmp);
  addRanking(r, "Footloose");
  addRanking(r, "Yesterday");
  addRanking(r, "La bamba");
  addRanking(r, "Sucio y desprolijo");
  addRanking(r, "Ride of the Valkyries");
  addRanking(r, "Yesterday");
  addRanking(r, "Ride of the Valkyries");

  const char * aux = "default";
  int n;
  n = getByRanking(r, 6, &aux);
  assert( n == 0 && !strcmp(aux, "default") );

  n = getByRanking(r, 1, &aux); 
  assert( n == 1 && !strcmp(aux, "Yesterday") );

  n = getByRanking(r, 0, &aux); 
  assert( n == 0 && !strcmp(aux, "Yesterday") );

  n = getByRanking(r, 2, &aux); 
  assert( n == 1 && !strcmp(aux, "Footloose") );

  n = getByRanking(r, 1, &aux); 
  assert( n == 1 && !strcmp(aux, "Footloose") );
 
  assert( contains(r, "Ride of the Valkyries") ); 
  assert( contains(r, "Sucio y desprolijo") ); 
  assert( contains(r, "Desarma y sangra") == 0 );

  size_t dimTop = 10;
  const char ** top = getTopRanking(r, &dimTop);
  assert(dimTop == 5 && !strcmp(top[0], "Footloose") && !strcmp(top[1], "Yesterday"));
  assert(!strcmp(top[2], "Ride of the Valkyries") && !strcmp(top[3], "Sucio y desprolijo"));
  assert(strcmp(top[4], "La bamba") == 0);
  free(top);

  downByRanking(r, 1);
  dimTop = 2;
  top = getTopRanking(r, &dimTop);
  assert( dimTop == 2 && !strcmp(top[0], "Yesterday") && !strcmp(top[1], "Footloose") );

  free(top);
  freeRanking(r);
  puts("rankingADT: OK!");
  return 0;
}