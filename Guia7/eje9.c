#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

#define BOLILLAS 90
#define FILA 5
#define COL 3

typedef int TipoLinea[FILA];
typedef TipoLinea TipoCarton[COL];

void GenerarCarton(TipoCarton carton)
{
    int n = BOLILLAS-1, vecaux[BOLILLAS], aux;

    for (int i = 0; i < BOLILLAS; i++)
    {
        vecaux[i] = i+1;
    }
    
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            aux = randInt(0, n);

            carton[i][j] = vecaux[aux];

            vecaux[aux] = vecaux[n];

            n--;
        }
    }   
}

int BuscarBolilla(TipoCarton carton, int bolilla)
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (carton[i][j] == bolilla)
            {
                carton[i][j] = 0;
                return 1;
            }
        }
    }
    return 0;
}

int ControlarLineas(TipoLinea linea)
{
    for (int i = 0; i < COL; i++)
    {
        if (linea[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

int ControlarCarton(TipoCarton carton, int bolilla)
{   
    int lineasCompletas=0;

    BuscarBolilla(carton, bolilla);

    for (int i = 0; i < FILA; i++)
    {
        if (ControlarLineas(carton[i]))
        {
            lineasCompletas++;
        }
    }
    return lineasCompletas;
}


void ImprimirCarton(TipoCarton carton)
{
    for (int i = 0; i < FILA; i++)
    {
        printf("\n");
        
        for (int j = 0; j < COL; j++)
        {
            if (carton[i][j] != 0)
            {
                printf("%d \t", carton[i][j]);
            }
        }
    }
    putchar('\n');
}


int SacarBolilla(int bolillero[], int *cantBolillas)
{
    int bolilla, aux;
    
    aux = ((randInt(1, *cantBolillas)) -1);

    (*cantBolillas)--;

    bolilla = bolillero[aux];

    bolillero[aux] = bolillero[*cantBolillas];

    return bolilla;
}

int jugar(int bolillero[], TipoCarton cartones[], int n)
{
    int huboLinea = 0, bolilla, cantBolillas = BOLILLAS;
    int lineas, resultado, i, bingo = 0;

    do
    {
        /* Imprimir los cartones de cada jugador */
        for (i = 0; i < n; i++)
        {
            printf("\nJugador %2d\n", i + 1);
            ImprimirCarton(cartones[i]);
        }

        /* Extraer una bolilla */
        bolilla = SacarBolilla(bolillero, &cantBolillas);
        printf("Bolilla extraida: %d\n", bolilla);

        /* Controlar si alguno hizo linea */
        /* Otra opcion seria tener un vector auxiliar en donde 
		** v[I]= 1 o 0 si el jugador I hizo linea o no
		*/
        for (lineas = 0, i = 0; i < n; i++)
        {
            resultado = ControlarCarton(cartones[i], bolilla);
            lineas |= resultado << i;

            /* Encendemos un bit en la variable bingo por cada jugador */
            if (resultado == 3)
                bingo |= 1 << i;
        }
        if (!huboLinea)
            for (i = 0; i < n; i++)
                if (lineas & (1 << i))
                {
                    printf("El jugador %2d hizo linea\n", i + 1);
                    huboLinea = 1;
                }
    } while (bingo == 0);

    return bingo;
}

int main(void)
{
    TipoCarton *cartones;

    int bolillero[BOLILLAS];

    int i, jugadores, bingo;

    randomize();

    for (i = 0; i < BOLILLAS; i++)
    {    
        bolillero[i] = i + 1;
    }

    do
    {
        jugadores = getint("Cantidad de jugadores :");
    } 
    while (jugadores < 1);

    if ((cartones = malloc(sizeof(TipoCarton) * jugadores)) == NULL)
    {
        printf("Hubo un error al reservar memoria.\n");
        return 1;
    }

    for (i = 0; i < jugadores; i++)
        GenerarCarton(cartones[i]);

    bingo = jugar(bolillero, cartones, jugadores);

    for (i = 0; i < jugadores; i++)
        if (bingo & (1 << i))
            printf("El jugador %d hizo bingo\n", i + 1);
    free(cartones);
    return 0;
}