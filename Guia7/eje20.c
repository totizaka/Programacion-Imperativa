#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <errno.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

#define BLOQUE 5

void freeAprobados(char** aprobados)
{
    for (int i = 0; *aprobados[i]; i++)
    {
        free(aprobados[i]);
    }
    free(aprobados);
}


char** aprobadosCurso(char* alumnos[], int* promedios)
{
    char** aprobados = NULL;

    int i, cantAprobados=0;

    for ( i = 0; alumnos[i][0] != '\0'; i++)
    {
        if (promedios[i] >= 4)
        {
            if (cantAprobados % BLOQUE == 0)
            {
                aprobados = realloc(aprobados, (cantAprobados + BLOQUE) * sizeof(char*));

                if (aprobados == NULL || errno == ENOMEM)
                {
                    if ( cantAprobados > 0) 
                    { 
                        aprobados[cantAprobados] = "";
                        freeAprobados(aprobados);
                    }
                    return NULL;
                }
            }

            aprobados[cantAprobados] = malloc(strlen(alumnos[i])+1);

            strcpy(aprobados[cantAprobados], alumnos[i]);
        
            cantAprobados++;
        }
    }
    aprobados = realloc(aprobados, (cantAprobados+1) * sizeof(char *));
    
    aprobados[cantAprobados]="";

    return aprobados;
}

int main()
{
    int promedios[] = {8, 3, 10, 7, 5, 6, 7, 3, 2, 1, 6, 8};
    char * alumnos [] = {"Ana", "Juan Pablo", "Mariana", "Fernando", "Carolina", "susana", "sol", "toti", "maria", "Esteban cardozo", "enrique sosa", "oliver giroud",""};

    char **  alumAprob;

    alumAprob = aprobadosCurso(alumnos, promedios);

    for (int i = 0; *alumAprob[i]; i++)
    {
        printf("%s\n", alumAprob[i]);
    }

    freeAprobados(alumAprob);
}