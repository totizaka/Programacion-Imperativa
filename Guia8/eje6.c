#include <stdio.h>
#include <math.h>
#include "../Biblioteca/getnum.h"

#define PARTCICIONES 100000
#define FUNCION(x) (sin(x))
#define EPSILON 0.000001
#define MEM_INC 10

typedef struct 
{
    double inicio;
    double final;
}Tipointervalo;

typedef struct 
{
    int cant;
    int dim;
    Tipointervalo* raices;
}TipoRaices;

void freeRaices(TipoRaices resp)
{
free(resp.raices);
}

void pedirIntervalo(Tipointervalo *intervalo)
{   
    do{
        (*intervalo).inicio = getdouble("ingresar inicio del intervalo");
        (*intervalo).final = getdouble("ingresar final del intervalo");
    }
    while((*intervalo).inicio >= (*intervalo).final);

    printf("intervalo: [%.4f, %.4f]", (*intervalo).inicio, (*intervalo).final);
}


double encontrarSumaParticiones(Tipointervalo intervalo)
{
    return (intervalo.final-intervalo.inicio+1)/PARTCICIONES;
}


int almacenarRaiz(TipoRaices* resp, Tipointervalo inter)
{
    Tipointervalo * aux;
    if (resp->dim == 0) /* Si es la primera vez que se invoca */
    {
        resp->raices = malloc(sizeof(Tipointervalo) * MEM_INC);
        if (!resp->raices)
        {
        resp->dim = -1; /* Si falla el pedido dim queda en –1 */
        return 0;
        }   
        resp->dim = MEM_INC;
    }
    else if (resp->cant == resp->dim) /* Si es necesario pedir más memoria */
    {
        aux = realloc(resp->raices, resp->dim + MEM_INC);
        if (!aux)
        {
        free(resp->raices);
        resp->dim = -1;
        return 0;
        }
        resp->dim += MEM_INC;
        resp->raices = aux;
    }
    /* Se almacena/actualiza el intervalo */
    resp->raices[resp->cant] = inter;
    return 1;
}


TipoRaices BuscoRaices(Tipointervalo intervalo, double suma)
{   
    double x, fx, fxant, incremento;
    TipoRaices respuesta;
    int esRaiz = 0, error = 0;
    Tipointervalo intActual;

    respuesta.cant=-1;
    respuesta.dim=0;
    
    x = intervalo.inicio;
    fxant = fx = FUNCION(x);

    while (x <= intervalo.final && !error)
    {
        if (fx * fxant < 0 || fabs(fx) < EPSILON)
        {
            if (!esRaiz)
            {
                respuesta.cant++;
                intActual.inicio = x - incremento;
            }
            if ( fx * fxant < 0 )
            {
                intActual.final = x;
            }
            else
            {
                intActual.final = x + incremento;
            }
            if (!almacenaRaiz(&respuesta, intActual))
            {
                error=1;
            }
            esRaiz = 1;
        }
        else
        {
            esRaiz=0;
        }
        x+=incremento;
        fxant=fx;

        fx = FUNCION(x);
    }
    respuesta.cant++;
    return respuesta;
}

void
verResultados(TipoRaices respuesta)
{
    int i;
    if (respuesta.dim == -1) /* Corresponde a error de malloc() */
        printf("Error en el almacenamiento de raíces\n");
    else if (respuesta.cant > 0)
    {
        for (i=0; i<respuesta.cant; i++)
        printf("\nRaíz %d en [%f,%f]\n",
        i+1,respuesta.raices[i].inicio, respuesta.raices[i].final);
    }
    else
    printf("\nNo hay raíces en ese intervalo\n");
}

int main()
{
    Tipointervalo intervalo;
    TipoRaices resultado;

    pedirIntervalo(&intervalo);

    double suma = encontrarSumaParticiones(intervalo);
    printf("suma = %f", suma);

}