#include <stdio.h>
#include <assert.h>
#include "../Biblioteca/random.h"

#define FILAS 4
#define COL 5

void swapFilas(int v1[], int v2[], int dim){

for (int i = 0; i < dim; i++)
{
    int aux = v1[i];

    v1[i]=v2[i];

    v2[i]=aux;
}
}

void ordenarFilas(int vec[][COL], int cantFIl, int cantCol, int numCol){

for (int i = 0; i < cantFIl; i++)
{
    int primerFila=i;

    for (int j = (i+1); j < cantFIl; j++)
    {
        if (vec[j][numCol - 1] < vec[primerFila][numCol - 1])
        {
            primerFila=j;
        }
        
    }
    if (primerFila!=i)
    {
        swapFilas(vec[i], vec[primerFila], cantCol);
    }
    
    
}

}

void generaMatriz(int cielo[][COL], int filas, int columnas)
{
    int i,j;

        for (i=0; i< filas; i++)
        {
            for (j=0; j < columnas; j++)
            {
                cielo[i][j] = randInt(0, 20);
            }
        }
}


int main(){

int vec[FILAS][COL];

randomize();

generaMatriz(vec, 4, 5);
ordenarFilas(vec,FILAS,COL,1);

    return 0;
}