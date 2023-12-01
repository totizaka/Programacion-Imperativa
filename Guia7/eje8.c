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

int jugar(TipoCarton carton1, TipoCarton carton2, int bolillero[])
{
    int bolilla, linCompletas1=0, linCompletas2=0;

    int cantBolillas = 90;

    while (linCompletas1 != 5 && linCompletas2 != 5)
    {
        bolilla = SacarBolilla(bolillero, &cantBolillas);

        printf("\n la bolilla extraida es %d", bolilla);

        linCompletas1 = ControlarCarton(carton1, bolilla);
        linCompletas2 = ControlarCarton(carton2, bolilla);

        printf("\nJugador 1:\n");
        ImprimirCarton(carton1);
        printf("\nJugador 2:\n");
        ImprimirCarton(carton2);

        if (linCompletas1 == 5)
        {
            printf("\nbingo jugador 1");
        }
        else if (linCompletas1 > 0)
        {
            printf("\nhay %d lineas completas del jugador 1", linCompletas1);
        }
    
        if (linCompletas2 == 5)
        {
            printf("\nbingo jugador 2");
        }
        else if (linCompletas2 > 0)
        {
            printf("\nhay %d lineas completas del jugador 2", linCompletas2);
        }
    }
    return 1;
}

int main()
{
    TipoCarton carton1, carton2;

    int bolillero[BOLILLAS];

    randomize();
    
    GenerarCarton(carton1);
    GenerarCarton(carton2);

    for (int i = 0; i < BOLILLAS; i++)
    {
        bolillero[i] = i+1;
    }

    jugar(carton1, carton2, bolillero);

    return 0;
}