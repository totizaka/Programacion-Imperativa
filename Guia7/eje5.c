#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

// int leerNombres(char nombre[])
// {
//     int i;
//     while (nombre[i]!='\0')
//     {
//         i++;
//     }
//     return i;
// }


// void ubicarNombres(char *nombre[], char **curso, int dim, int i)
// {
//     if (dim % TAM == 0)
//     {
//         realloc(*curso, (dim + TAM) * sizeof(char*));
//     }
//     curso[dim] = malloc(leerNombres(nombre[i]) * sizeof(char));

//     strcpy(curso[dim++], nombre[i]);
// }


void ordenados(char ** cursoG, char ** cursoH, char *nombre[], char *curso)
{
    int dimG=0, dimH=0;
    int i=0;

    cursoG = NULL;
    cursoH = NULL;

    do
    {
        if (curso[i] =='G')
        {
            if (dimG % TAM == 0)
            {
                realloc(*cursoG, (dimG + TAM) * sizeof(char*));
            }
            // cursoG[dimG] = malloc(leerNombres(nombre[i]) * sizeof(char));
            // strcpy(cursoG[dimG++], nombre[i]);

            cursoG[dimG] = nombre[i];
        }
        else
        {
            if (dimH % TAM == 0)
            {
                realloc(*cursoH, (dimH + TAM) * sizeof(char*));
            }
            // cursoH[dimH] = malloc(leerNombres(nombre[i]) * sizeof(char));

            // strcpy(cursoH[dimH++], nombre[i]);

            cursoH[dimH] = nombre[i];
        }
            i++;
        
    } while (nombre[i][0]!=0);
    
}


// int main(void){

//     char *alumnos[]={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
//     char curso[]={'H', 'G', 'H', 0};
//     separaCursos(alumnos, curso, cursoG, cursoH);
//     assert(!strcmp(cursoG[0], alumnos[1]));
//     assert(!strcmp(cursoH[0], alumnos[0]));
//     assert(!strcmp(cursoH[1], alumnos[2]));
//     assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con "" 

//     alumnos[0]=""; curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
//     separaCursos(alumnos, curso, cursoG, cursoH);
//     assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

//     puts("OK!");
//     return 0;
// }