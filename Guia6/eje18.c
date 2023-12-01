#include <stdio.h>
#include <assert.h>

#define COLS 4


int CompFilas(int vec1[], int vec2[])
{                                                   //funcion para comparar filas

    int esta=0, i=0, j=0;                    

    if (vec1[0]<vec2[0])                            //si el primer num del v1 es mas chico que el primero de v2
        {                                           //salgo, xq esta en ascendente
            return 0;               
        }

    while (i < COLS && j < COLS)                    //mientras no nos pasemos de columnas
    {
        if (vec1[i] == vec2[j])                     //veo si son iguales
        {
            i++;                                    //si son iguales paso al sig num de la primera matriz
            esta++;                                 //aumento la variable esta
        }
        else
            j++;                                    //si no son iguales paso al sig num de la seg matriz
    }

    return esta == COLS;                                   //sino retorno 0
    
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

int 
main(void)
{
  int m1[][COLS] = {{0,1,2,3}, {4,4,5,6}, {7,8,8,9}};
  int m2[][COLS] = {{0,1,2,3}, {-3,7,8,9}, {-1,3,4,7}, {4,5,6,8}};
  int m3[][COLS] = {{2,3,3,7}};
  assert(sonAmigas(m1,3,m2,4)==1);
  assert(sonAmigas(m1,1,m2,4)==1);
  assert(sonAmigas(m1,2,m2,4)==1);
  assert(sonAmigas(m1,2,m2,2)==0);
  assert(sonAmigas(m2,4,m1,3)==2);
  assert(sonAmigas(m1,3,m3,1)==0);
  assert(sonAmigas(m3,1,m1,3)==0);
  int res = sonAmigas(m1,3,m1,3);
  assert(res==1 || res==2);
  
  printf("OK !\n");

  return 0;
}