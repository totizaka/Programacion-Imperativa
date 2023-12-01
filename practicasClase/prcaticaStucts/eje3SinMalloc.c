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
typedef struct tipoLibro  tipoBiblioteca[CANT_LIBROS];

/* Función devuelve un libro */
tipoLibro carga (void);

/* Función que imprime el libro */
void imprime(tipoLibro libro);

int 
main3(void)
{
    tipoBiblioteca biblioteca;
    
	int i;
	
	/* Se leen los libros */
	for (i=0; i< CANT_LIBROS; i++)
		biblioteca[i] = carga(); 

	/* Se imprimen los libros */
	for (i=0; i< CANT_LIBROS; i++)
		imprime(biblioteca[i]);
    

	return 0;
}

tipoLibro
carga (void)
{
	tipoLibro aux;
	printf("Titulo: ");
    getLine(aux.titulo, MAX);
    printf("Autor: ");
    getLine(aux.autor, MAX);
    printf("ISBN: ");
    getLine(aux.ISBN, ISBEN_MAX);
    aux.precio = getfloat("Precio:");
	return aux;
}	

void 
imprime(tipoLibro libro)
{
	printf("Titulo: %s ", libro.titulo);
	printf("Autor: %s \n", libro.autor);
	printf("ISBN: %s ", libro.ISBN);
	printf("Precio: %g \n", libro.precio);
}	