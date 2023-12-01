#include <stdio.h>
#include <string.h>
#include "../Getnum/getnum.h"

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
    char   * titulo;
    char   * autor;
    char    ISBN[ISBEN_MAX + 1];
    float   precio;
} tipoLibro; /* Se puede repetir el nombre optativo en el typedef */

/* Se define el tipo de dato tipoBiblioteca con un typedef */

#define CANT_LIBROS	10

typedef struct tipoLibro * tipoBiblioteca;

/* Función devuelve un libro */
tipoLibro carga (void);

/* Función que imprime el libro */
void imprime(tipoLibro libro);

int 
main3(void)
{
    int cant;
    do
    {
        cant = getint("ingresar cant de libros");
    } while (cant<1);
    
    tipoBiblioteca biblioteca = malloc(cant * sizeof(tipoLibro));
    
	int i;
	
	/* Se leen los libros */
	for (i=0; i < cant; i++)
		biblioteca[i] = carga(); 

	/* Se imprimen los libros */
	for (i=0; i < cant; i++)
		imprime(biblioteca[i]);
    
    //...................................

    for (i=0; i < cant; i++){

        free(biblioteca[i].titulo);
        free(biblioteca[i].autor);
    }

    free(biblioteca);

	return 0;
}

tipoLibro
carga (void)
{
	tipoLibro aux;
	printf("Titulo: ");
    aux.titulo = getLineNoLimit();
    printf("Autor: ");
    aux.autor = getLineNoLimit();
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
