#include <stdio.h>
#include <string.h>
#include "../Getnum/getnum.h"

#define MAX 30
#define ISBEN_MAX 10

int Getline(char v[], size_t max) {
    int c;
    int i=0;

    while ( (c=getchar()) != '\n' && c != EOF) {
        if ( i < max) {
            v[i++] = c;
        }
    }
    v[i]=0;
    return i;
}

typedef struct tipoLibro {
    char     titulo[MAX+1];
    char    autor[MAX+1];
    char    ISBN[ISBEN_MAX + 1];
    float   precio;
} tipoLibro; /* Se puede repetir el nombre optativo en el typedef */

/* Se define el tipo de dato tipoBiblioteca con un typedef */
#define CANT_LIBROS	10
typedef struct tipoLibro tipoBiblioteca[CANT_LIBROS];

/* Funcion que carga un libro */
void carga (tipoLibro * libro);

/* Funcion que imprime el libro */
void imprime(const tipoLibro * libro);

int
main2(void)
{
	tipoBiblioteca biblioteca;
	int i;
	
	/* Se leen los libros */
	for (i=0; i< CANT_LIBROS; i++)
		carga(&biblioteca[i]);  /* Una forma de enviar la direccion */   

	/* Se imprimen los libros */
	for (i=0; i< CANT_LIBROS; i++)	
		imprime(biblioteca+i);  /* Otra forma de enviar la direccion */    

	return 0;
}

void 
carga (tipoLibro * libro)
{
	printf("Titulo: ");
    getLine(libro->titulo, MAX);   // (*libro).titulo
    printf("Autor: ");
    getLine(libro->autor, MAX);
    printf("ISBN: ");
    getLine(libro->ISBN, ISBEN_MAX);
    libro->precio = getfloat("Precio:");
}	

void 
imprime(const tipoLibro * libro)
{
	printf("Titulo: %s ", libro->titulo);
	printf("Autor: %s \n", libro->autor);
	printf("ISBN: %s ", libro->ISBN);
	printf("Precio: %g \n", libro->precio);
}	
