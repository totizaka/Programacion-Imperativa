#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "../Getnum/getnum.h"

#define PALOS 4
#define MAX 15

// Lee hasta el \n pero deja en el vector hasta MAX caracteres (y el cero)
// Es responsabilidad del usuario haber reservado al menos max+1 bytes

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


int main(void) {
    
    int dim;
    do {
        dim = getint("Jugadores iniciales");
    } while (dim < 1);

    char * *palos = malloc(dim * sizeof(char *));
    
    char aux[MAX+1];                                // Vector auxiliar donde leer los nombres


    // Para cada palo:
    //    Leo hasta MAX chars en aux
    //    Reservo strlen(aux)+1
    //    Copio
    for(int i=0; i<dim; i++) {
        palos[i] = malloc(Getline(aux, MAX) + 1);
        strcpy(palos[i], aux);
    }
    for(int i=0; i<dim; i++) {
        puts(palos[i]);
    }

    palos[3] = realloc(palos[3], strlen(palos[3]) + 15);
    strcat(palos[3], " el mas grande");

    dim++;
    // Agregamos uno
    palos = realloc(palos, dim * sizeof(*palos));
    palos[dim-1] = malloc(10);
    strcpy(palos[dim-1], "Fin");

    for(int i=0; i<dim; i++) {
        puts(palos[i]);
    }
    // Ahora el usuario indica cual es cada palo
    for(int i=0; i<dim; i++) {
        free(palos[i]);
    }

    free(palos);

    return 0;
}