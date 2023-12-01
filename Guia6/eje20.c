#include <stdio.h>
#include <assert.h>

#define DIM 9


int numCorrectos(char mat[][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (mat[i][j] < 1 && mat[i][j] >9)
            {
                return 0;
            }   
        }
    }
    return 1;
}


int chequearFil(char vec[])
{
    int vecaux[DIM] = {0};                        // vector auxiliar para marcar si un dígito ya estaba
   
    int aux, ok = 1;

    for (int i = 0; i < DIM && ok; i++)
    {
        aux = vec[i]-1;
        
        if ( vecaux[aux] == 0 )
        {
                vecaux[aux]++;
        }
        else
        {
                ok = 0; 
        }
    }
    return ok;
}


int chequearCol(char vec[][DIM], int col)
{
    int vecaux[DIM]={0};

    int aux, ok=1;

    for (int i = 0; i < DIM && ok; i++)
    {
        aux = (vec[i][col] - 1);

        if (vecaux[aux] == 0)
        {
            vecaux[aux]++;
        }
        else
            ok=0;
    }
    return ok;
}


int chequearSubb(char mat[][DIM])
{
    int aux, ok=1;
    
    for (int fil = 1; fil < DIM; fil+=3)
    {
        for (int col = 1; col < DIM; col+=3)
        {
            int vecaux[DIM]={0};

            for (int i = (fil-1); i <= (fil+1) && ok; i++)
            {
                for (int j = (col-1); j <= (col+1) && ok; j++)
                {
                    aux = (mat[i][j] - 1);

                    if (vecaux[aux] == 0)
                    {
                        vecaux[aux]++;
                    }
                    else
                        ok=0;
                }
            }
        }
    }
    return ok;
}



int sudokuSolver(char mat[][DIM])
{
    if (!numCorrectos(mat))
    {
        return 0;
    }

    for (int i = 0; i < DIM; i++)
    {
        if (!chequearFil(mat[i]))
        {
            return 0;
        }
    }

    for (int j = 0; j < DIM; j++)
    {
        if (!chequearCol(mat, j))
        {
            return 0;
        }
    }
    
    return chequearSubb(mat);
}
    
int main(void) {
  // Una matriz vacía no es solución
  char sudoku[DIM][DIM] = {{0}};

  assert(sudokuSolver(sudoku)==0);

  char sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku2)==1);
  
  char sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2}, 
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku3)==0);
  
  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  char sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}
  };

  assert(sudokuSolver(sudoku4)==0);

  char sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku5)==0);

  return 0;
}
    