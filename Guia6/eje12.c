#include <stdio.h>
#include "../Biblioteca/random.h"

#define FILAS 5
#define COL 5

int matrizTranspuesta( int matriz[][COL], int dim){

int i, j, aux;

for (i = 0; i < dim; i++)
{
    for (j=0; j < i; j++)
    {
        aux = matriz[i][j];

        matriz[i][j] = matriz[j][i];

        matriz[j][i] = aux;
        
    }
}

    return 0;
}

int main(){

int matriz[FILAS][COL]= {{1,1,1,1,1}, {2,2,2,2,2}, {3,3,3,3,3}, {4,4,4,4,4}, {5,5,5,5,5}};

matrizTranspuesta(matriz,5);

for (int i = 0; i < 5; i++)
{
    for (int j = 0; j <5; j++)
    {
    printf("%d ", matriz[i][j]);
    }
    putchar('\n');
}
putchar('\n');


return 0;

}

//          1 1 1 1 1           1 2 3 4 5
//          2 2 2 2 2           1 2 3 4 5
//          3 3 3 3 3           1 2 3 4 5
//          4 4 4 4 4           1 2 3 4 5
//          5 5 5 5 5           1 2 3 4 5