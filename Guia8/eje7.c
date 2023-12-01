#include <stdio.h>
#include <string.h>
#include <assert.h>

#define COLS 7
#define FILS 6

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;

struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
};

struct posicion* resolverSopa(char sopa[FILS][COLS], char *diccionario[])
{
    int primeraEsta, letra=0;

	for (int i = 0; diccionario[i] != ""; i++)
	{
		for (int fil = 0; fil < FILS; fil++)
		{
			for (int col = 0; col < COLS; col++)
			{
				if (sopa[fil][col] == diccionario[i][letra])
				{
					
				}
			}
		}
	}
}


int main(void) {
  char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
   
  char sopa[FILS][COLS] =
     {{'X','X','X','O','X','X','X'},
      {'A','P','A','C','Y','Y','O'},
      {'Z','E','Z','R','Z','C','X'},
      {'E','R','R','O','R','X','X'},
      {'X','R','I','O','I','E','X'},
      {'X','O','X','X','O','X','X'}};
  
  struct posicion * res = resolverSopa(diccionario, sopa);
  // La cantidad de palabras encontradas debe ser 9
  int expected = 9;
  int count = 0;
  while ( res[count].palabra != NULL)
     printf("%s\n", res[count++].palabra);
  assert(count == expected);

  assert(strcmp(res[0].palabra,"ARRE")==0);
  assert(res[0].fila==1);
  assert(res[0].columna==2);
  assert(res[0].direccion==D_AB);

  assert(strcmp(res[3].palabra,"ORCO")==0);
  assert(res[3].fila==3);
  assert(res[3].columna==3);
  printf("%d\n", res[3].direccion);
  assert(res[3].direccion==ARR);
  
  assert(strcmp(res[4].palabra,"ORCO")==0);
  assert(res[4].fila==4);
  assert(res[4].columna==3);
  assert(res[4].direccion==D_AR);

  assert(strcmp(res[6].palabra,"REA")==0);
  assert(res[6].fila==3);
  assert(res[6].columna==2);
  assert(res[6].direccion==I_AR);

  puts("OK");
  return 0;
}