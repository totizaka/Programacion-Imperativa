#include <stdio.h>
#include "../Biblioteca/random.h"
#include "../Biblioteca/getnum.h"

#define FILAS 20
#define COLUMNAS 80

int sum1Fila=0, suma=0, intensidad=0;

void estrellas(int vec[][COLUMNAS], int dim1, int dim2){

for (int fila = 1; fila < dim1-1; fila++)
{
    printf("\n");

    for (int col = 1; col < dim2-1; col++)
    {
        suma=0;

        for ( int filsum = (fila-1); filsum <= (fila+1); filsum++)
        {
            for ( int colsum = (col-1); colsum < (col+1); colsum++)
            {
                sum1Fila+=vec[filsum][colsum];
            }
            
            suma+=sum1Fila;
            sum1Fila=0;
        }
        
        // intensidad=(suma/9)

        if ((suma/9)>10)
        {
            putchar('*');
        }
        else
        {
            putchar(' ');
        }
    }
}
}

void generaMatriz(int cielo[][COLUMNAS], int filas, int columnas)
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

// int graficar(num){

// if (num>10)
// {
//     return 1;
// }
// else
//     return 0;
// }




int main(){

int cielo[FILAS][COLUMNAS];

randomize();

generaMatriz(cielo,FILAS,COLUMNAS);

estrellas(cielo,FILAS,COLUMNAS);

printf("\n");

    return 0;
}