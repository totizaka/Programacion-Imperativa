#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOQUE 5

static void mostrarNombres(char* arrNombres[], size_t n)
{
    for (size_t i=0; i<n; i++)
    {
        printf("%s\n", arrNombres[i]);
    }
}

int obtenerAprobados(char* arrNombres[], int tam, char* aprobados[], int notas[])
{
    aprobados=NULL;
    
    int cantAprobados=0;
    int dim = 0;

    for (; dim < tam; dim++)
    {
        if (notas[dim] >= 4)
        {
            if (cantAprobados % BLOQUE == 0)
            {
                aprobados = realloc(aprobados, ((cantAprobados + BLOQUE) * sizeof(char*)));
            }
            aprobados[cantAprobados] = malloc(strlen(arrNombres[dim]+1));
            
            strcpy(aprobados[cantAprobados++], arrNombres[dim]);
        }
    }
}
