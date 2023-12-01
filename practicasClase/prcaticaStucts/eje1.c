#include <stdio.h>
#include <string.h>
#include "getnum.h"

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

struct tipoLibro {
	char 	titulo[MAX+1];
	char	autor[MAX+1];
	char	ISBN[ISBEN_MAX + 1];
	float   precio;
};

/* Se define el tipo de dato tipoBiblioteca con un typedef */
#define CANT_LIBROS	10
typedef struct tipoLibro tipoBiblioteca[CANT_LIBROS];

/* Funcion que carga un libro en la posicion index de la biblioteca */
void carga (tipoBiblioteca bib, int index);

/* Función que imprime el libro de la posicion index de la biblioteca */
void imprime(tipoBiblioteca bib, int index);

int 
main(void)
{
	tipoBiblioteca biblioteca;
	int i;
	
	/* Se leen los libros */
	for (i=0; i< CANT_LIBROS; i++)
		carga(biblioteca,i);   

	/* Se imprimen los libros */
	for (i=0; i< CANT_LIBROS; i++)
		imprime(biblioteca,i);   

	return 0;
}

void 
carga (tipoBiblioteca bib, int index)
{
    printf("Titulo: ");
    getLine(bib[index].titulo, MAX);
    printf("Autor: ");
    getLine(bib[index].autor, MAX);
    printf("ISBN: ");
    getLine(bib[index].ISBN, ISBEN_MAX);
    bib[index].precio = getfloat("Precio: ");
}	

void 
imprime(tipoBiblioteca bib, int index)
{
	printf("Titulo: %s ", bib[index].titulo);
	printf("Autor: %s \n", bib[index].autor);
	printf("ISBN: %s ", bib[index].ISBN);
	printf("Precio: %g \n", bib[index].precio);
    
}	