#include <stdio.h>

#define FILA 3
#define COL 3



int filaXcol(int fila[], int cols[][COL], int dim, int col){

int total=0;

    for (int i = 0; i < dim; i++)
    {
        total += ((fila[i]) * (cols[i][col]));
    }

    return total;
}


void multMatrices(int vec1[][COL], int vec2[][COL], int dim, int res[][COL]){

for (int r = 0; r < dim; r++)
{
    for (int i = 0; i < dim; i++)
    {
        res[r][i] = filaXcol(vec1[r], vec2, dim, i);
    }
}
}


int main(){

int vec1[FILA][COL]={{2,0,1}, {3,0,0}, {5,1,1}};

int vec2[FILA][COL]={{1,0,1}, {1,2,1}, {1,1,0}};

int res[FILA][COL];

multMatrices(vec1, vec2, 3, res);

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("%d ",res[i][j]);
    }
    putchar('\n');
}


    return 0;
}




//                   00                                          01                                        02


//    (00 * 00) + (01 * 10) + (02 * 20)           (00 * 01) + (01 * 11) + (02 * 21)         (00 * 02) + (01 * 12) + (02 * 22)


//    (10 * 00) + (11 * 10) + (12 * 20)


//    (20 * 00) + (21 * 10) + (22 * 20)



