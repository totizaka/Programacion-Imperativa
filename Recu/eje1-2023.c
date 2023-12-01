#include <stdio.h>
#include <stdlib.h>
#include "eje1-2023.h"
#include <strings.h>
#include <string.h>

#define DIAS 365

typedef struct node
{
    char* nombre;
    struct node* tail;
}Tnode;

typedef Tnode* Tvisitor;

typedef struct dia
{
    Tvisitor first;
    Tvisitor next;
    size_t cant;
}Tdia;

typedef struct museumTicketCDT
{
    Tdia anio[365];
    size_t cantTot;
}museumTicketCDT;


/**
* Reserva los recursos para administrar las ventas de tickets para visitar un museo en
* un año determinado
* Nota: Como no se indica el año para el que se lo utilizará se asume que el
* año será siempre bisiesto
*/
museumTicketADT newMuseumTicket(void)
{
    museumTicketADT nuevo = calloc(1, sizeof(museumTicketCDT));
    return nuevo;
}

/**
* Se registra un ticket para que #visitor visite el museo el día #dayOfYear del año
* Retorna la cantidad actual de tickets registrados para visitar el museo ese día
* Retorna 0 si #dayOfYear es igual a 0 o mayor a 366
* Retorna 0 si ya se había registrado un ticket para ese #visitor y ese #dayOfYear
*/
Tvisitor addRec(Tvisitor list, char* visitor, int* agrego)
{
    int c;
    if ( list == NULL || (c = strcasecmp(list->nombre, visitor))>0)
    {
        Tvisitor aux = malloc(sizeof(Tnode));
        aux->nombre = visitor;
        aux->tail = list;
        *agrego = 1;
        return aux;
    }
    else if (c < 0)
    {
        list->tail = addRec(list->tail, visitor, agrego);
    }
    return list;
}
int addTicket(museumTicketADT museum, size_t dayOfYear, const char * visitor)
{
    if (dayOfYear == 0 || dayOfYear > 365)
    {
        return 0;
    }
    int agrego;
    museum->anio[dayOfYear-1].first = addRec(museum->anio[dayOfYear-1].first, visitor, &agrego);
    if (agrego)
    {
        museum->anio[dayOfYear-1].cant+=agrego;
        museum->cantTot+=agrego;
        return museum->anio[dayOfYear-1].cant;
    }
    else
        return 0;
}

/**
* Retorna la cantidad de tickets registrados para visitar el museo el día #dayOfYear
* del año
* Retorna -1 si #dayOfYear es igual a 0 o mayor a 366
*/
int dayTickets(const museumTicketADT museum, size_t dayOfYear)
{
    if (dayOfYear = 0 || dayOfYear > DIAS)
    {
        return -1;
    }
    return museum->anio[dayOfYear-1].cant;
}

void toBeginByDay(museumTicketADT museum, size_t dayOfYear)
{
    if (dayOfYear = 0 || dayOfYear > DIAS)
    {
        exit(1);
    }
    museum->anio[dayOfYear-1].next = museum->anio[dayOfYear-1].first;
}