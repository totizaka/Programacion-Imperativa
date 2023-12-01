#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PALOS 4

int main(){                         //Version inicial: 4 strings "de entrada")
    
    char* palos[PALOS];

    palos[0] = malloc(5);
    strcpy(palos[0], "Copa");               // palos[0][0] = 'C';  que es lo mismo que *palos[0] = 'C';

    palos[1] = malloc(6);
    strcpy(palos[1], "Basto");

    palos[2] = malloc(4);
    strcpy(palos[2], "Oro");

    palos[3] = malloc(7);
    strcpy(palos[3], "Espada");              // Los imprimimos en orden

    for(int i=0; i<PALOS; i++) {
        puts(palos[i]);
    }

    // Quiero que el último palo sea "Espadita"
    palos[3] = realloc(palos[3], strlen("Espadita")+1);
    strcpy(palos[3], "Espadita");
    puts("");

    for(int i=0; i<PALOS; i++) {
        puts(palos[i]);
    }

    for(int i=0; i<PALOS; i++) {
        free(palos[i]);
    }
}