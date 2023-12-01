#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
#include "eje15.h"
#include <string.h>

typedef struct alumnos
{
    int legajo;
    char* nombre;
}Talumnos;

typedef struct cursoCDT
{
    Talumnos vec[50];
    char* nombrecurso;
    int cant;
    int size;
}cursoCDT;

typedef cursoCDT* cursoADT;
