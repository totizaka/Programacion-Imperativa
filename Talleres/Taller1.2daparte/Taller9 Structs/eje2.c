#include <stdio.h>
#include <stdlib.h>
#include "../Biblioteca/getnum.h"

#define MAX_LONG 15
#define TOTAL_ITEMS 10


typedef struct 
{
    int codigo;
    char desc[MAX_LONG];
    float precio;

}tItem;

typedef tItem tFactura[TOTAL_ITEMS];

tItem leerItem()
{
    tItem item;

    item.codigo = getint("Codigo:");
    while (item.codigo <= 0)
    {
        item.codigo = getint("Codigo:");
    }

    item.precio = getfloat("Precio:");
    while (item.precio <= 0)
    {
        item.precio = getfloat("Precio:");
    }
    
    printf("Descripcion: ");
    while (fgets(item.desc, MAX_LONG, stdin) == NULL || item.desc[0] == '\n')
    {
        printf("Descripcion: ");
    }
    return item;
}

void cargar(tFactura f, int cant)
{
    for (size_t i = 0; i < cant; i++)
    {   
        printf("Nuevo Item");

        f[i] = leerItem();
    }
}

float importe(tFactura f, int cant)
{
    int i;
    float suma;

    for (i = 0; i < cant; i++)
    {
        suma+=f[i].precio;
    }
    return suma;
}

int main(void) 
{
    tFactura f;
    cargar(f, TOTAL_ITEMS);
    printf("%.2f", importe(f, TOTAL_ITEMS));
    return 0;
}