#include <stdio.h>

// #define COLS 6

// int elimina (char matriz[ ][COLS], int dim )
// {
//   int iguales, fil2=0;
 
//   for (int i=0; i<dim; i++)
//   {
//     iguales=1;
 
//     for (int j=0; j<(COLS/2) && iguales; j++)
//     {
//       if (matriz[i][j] != matriz[i][(COLS-1)-j])
//       {
//         iguales=0;
//       }
//     }
//     if (!iguales)//si no es capicua
//     {
//       for (int r=0; r<COLS; r++)
//       {
//         matriz[fil2][r] = matriz[i][r];
//       }
//       fil2++;
//     }
//   }
//   return fil2;
// }

// int main(){

// char matriz[COLS][COLS] = {{'a','s','r','r','s','a'},
//                          {'s','u','r','r','d','s'},
//                          {'f','s','d','d','s','f'},
//                          {'c','v','d','d','t','c'},
//                          {'f','t','g','g','t','f'},
//                          {'y','g','h','h','g','y'}};

//   printf("%d\n\n", elimina(matriz, 6));
//   for (int i = 0; i < COLS; i++)
//   {
//     for (int f = 0; f < COLS; f++)
//     {
//       printf("%c", matriz[i][f]);
//     }
//     printf("\n");
    
//   }
  
// }

#define M 4

int sumFilsBorde(int matriz[][M], int fila)
{
  fila-=1;
  int col=fila;
  int suma=0;
 
  for (int i=0; fila < M-col && i<2; i++, fila+=((M-1)-(fila*2)))
  {
    for (int i=col; i < M-col; i++)
    {
      suma += matriz[fila][i];
    }
  }

return suma;
}
 
int sumColsBorde(int matriz[][M], int col)
{
  col-=1; 
  int filmin=(col+1);
  int suma=0;

  for (int i=0; col < M && i<2; i++, col+=((M-1)-(col*2)))
  {
    for (int i=filmin; i < M-filmin; i++)
    {
      suma += matriz[i][col];
    }
  }

return suma;
}

void bordes (int matriz[][M], int vec[])
{
  for (int borde=1; borde < ((M/2)+1); borde++)
  {
    vec[(borde-1)] = (sumFilsBorde(matriz, borde) + sumColsBorde(matriz, borde));
  }
  return;
}
 



int main(){

int vec[M/2]={0};

// int matriz[][M] = {{1,1,1,1,1,1},
//                   {1,2,2,2,2,1},
//                   {1,2,3,3,2,1},
//                   {1,2,3,3,2,1},
//                   {1,2,2,2,2,1},
//                   {1,1,1,1,1,1}};

int matriz[][M] = {{1,1,1,1},
                    {1,2,2,1},
                    {1,2,2,1},
                    {1,1,1,1}};

  bordes(matriz, vec);

  printf("Los bordes son: (");
  for (int i = 0; i < M/2; i++){
    printf(" %d ", vec[i]);
  }
  printf(")\n");
  

  return 0;
}