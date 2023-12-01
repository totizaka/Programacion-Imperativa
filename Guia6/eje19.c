#include <stdio.h>
#include <assert.h>

#define COLS 4


int CompFilas(int vec1[], int vec2[])
{                                                   //funcion para comparar filas
    int esta=0;                    

    for (int i =0; i < COLS; i++)
    {
        for (int j=0; j < COLS ; j++)                    //mientras no nos pasemos de columnas
        {
            if (vec1[i] == vec2[j])                     
            {
                esta++;
                break;                                 
            }
        }                                  
    }
    return esta == COLS; 
}



int filaAmiga(int m1[][COLS], int fils1, int m2[][COLS], int fils2)
{                                                                       //para ver si una fila de la primer matriz
    int esta;                                                         //es amiga de una de la segunda matriz

    for (int i = 0; i < fils1; i++)
    {
        esta=0;

        for (int j = 0; j < fils2 && !esta; j++)
        {
            if (CompFilas(m1[i], m2[j]))                                //uso comparo filas para ver si coincide con alguna
            {
                esta=1;                                                 //si es amiga prendo la flag
            }
        }
        
        if (esta != 1)                                                  //si no es amiga la flag no esta prendida, retorno 0
        {
            return 0;
        }
    }
    return 1;
}



int sonAmigas(int m1[][COLS], unsigned int fils1, int m2[][COLS], unsigned int fils2)
{

    if (filaAmiga(m1, fils1, m2, fils2))                                //veo si matiz 1 es amiga de matriz 2
    {
        return 1;
    }
    else if (filaAmiga(m2, fils2, m1, fils1))                           //veo si matriz 2 es amiga de matriz 1
    {
        return 2;
    }

    return 0;

}
