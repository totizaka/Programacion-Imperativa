#include <stdio.h>
#include <assert.h>

#define ALTO 6
#define ANCHO 5

#define MAX(x,y) ( (x) > (y) ? (x) : (y) )
#define MIN(x,y) ( (x) < (y) ? (x) : (y) )


int media(unsigned char vec[ALTO][ANCHO], int fil, int col, int w){

    int suma=0, cant=0;  
    
    w=w/2;

        for (int r = MAX(0, fil - w); r <= MIN(ALTO - 1, fil + w) ; r++)
        {
            for (int h = MAX(0, col - w); h <= MIN(ANCHO - 1, col + w) ; h++)
            {
                suma+= vec[r][h];
                cant++;
            }   
        }

    return suma/cant;
}


int copiar(unsigned char mat[ALTO][ANCHO], unsigned char matAux[ALTO][ANCHO], int fils, int cols){

    for (int i = 0; i < fils; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                mat[i][j] = matAux[i][j];
            }
        }
    return 0;
}


int suavizar(unsigned char mat[ALTO][ANCHO], int w){

    if (w < 3 || w % 2 == 0)
    {
        return 0;
    }

    unsigned char matAux[ALTO][ANCHO];

    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            matAux[i][j] = media(mat, i, j, w);
        }
    }

   copiar(mat, matAux, ALTO, ANCHO);

    return 0;
}



