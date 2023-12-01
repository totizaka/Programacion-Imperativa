#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAX 10

void diagonal(int matrix[][MAX], int dim, int fila, int columa, int dirFil, int dirCol)
{
    if (fila >= dim || columa >= dim || fila < 0 || columa < 0)
    {
        return;
    }
    matrix[fila][columa] = !matrix[fila][columa];
    diagonal(matrix, dim, fila + dirFil, columa + dirCol, dirFil, dirCol);
}

void reemplazo(int matrix[][MAX], int dim, int fila, int columa)
{
    if (fila >= dim || columa >= dim || fila < 0 || columa < 0)
    {
        return;
    }
    matrix[fila][columa] = !matrix[fila][columa];

    diagonal(matrix, dim, fila-1, columa-1, -1, -1);
    diagonal(matrix, dim, fila-1, columa+1, -1, 1);
    diagonal(matrix, dim, fila+1, columa-1, 1, -1);
    diagonal(matrix, dim, fila+1, columa+1, 1, 1);
}


#define MAX 10

void reemplazo(int matriz[][MAX], int dim, int fil, int col);

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  reemplazo(m, 5, 1, 2);
  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}