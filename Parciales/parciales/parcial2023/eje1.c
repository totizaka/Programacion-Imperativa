#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "eje1.h"
#include <assert.h>

#define DIAS 365
 
typedef struct nombre{
    char* visitor;
    struct nombre* tail;
}Tnombre;
 
typedef Tnombre* Tvisitor;
 
typedef struct dia{
    Tvisitor visitor;
    Tvisitor next;
    int cantDayTickets;
}Tdia;
 
typedef struct museumTicketCDT{
    Tdia dia[DIAS];
    int cantYearTickets;
}museumTicketCDT;
 
museumTicketADT newMuseumTicket()
{
    museumTicketADT nuevo = calloc(1, sizeof(museumTicketCDT));
    return nuevo;
}
 
Tvisitor addRec(Tvisitor visitor, char* nombre, int* agrego)
{
    int c;
    if (visitor == NULL || (c=(strcasecmp(nombre, visitor->visitor))<0))
    {
        Tvisitor aux = malloc(sizeof(Tnombre));
        aux->visitor = nombre;
        aux->tail = visitor;
        (*agrego) = 1;
        return aux;
    } 
    else if (c > 0)
    {
        visitor->tail = addRec(visitor->tail, nombre, agrego);
    }
    return visitor;
}
int addTicket(museumTicketADT museum, size_t dayOfYear, char* visitor)
{
    int agrego=0;
    if (dayOfYear == 0 || dayOfYear > DIAS)
    {
        return 0;
    }
    museum->dia[dayOfYear-1].visitor = addRec(museum->dia[dayOfYear-1].visitor, visitor, &agrego);
    if (agrego)
    {
        museum->dia[dayOfYear-1].cantDayTickets+=agrego;
        museum->cantYearTickets+=agrego;
        return museum->dia[dayOfYear-1].cantDayTickets;
    }
    return 0;
}
 
int dayTickets (const museumTicketADT museum, size_t dayOfYear)
{
    if (dayOfYear == 0 || dayOfYear >= DIAS)  
    {
      return -1;
    }
    return museum->dia[dayOfYear-1].cantDayTickets;
}
 
void ToBeginByDay(museumTicketADT museum, size_t dayOfYear)
{
    museum->dia[dayOfYear-1].next = museum->dia[dayOfYear-1].visitor;
}


int
main(void) {
// Reserva los recursos para administrar las ventas de tickets
museumTicketADT museum = newMuseumTicket();
// Se registra un ticket para que John visite el museo el día 4 del año
// Y retorna 1 porque es la cantidad de tickets para ese día
assert(addTicket(museum, 4, "John") == 1);
// Los siguientes fallan porque John ya cuenta con un ticket para el día 4 del año
assert(addTicket(museum, 4, "John") == 0);
assert(addTicket(museum, 4, "JOHN") == 0);
assert(addTicket(museum, 4, "john") == 0);
// Se registra un ticket para que John visite el museo el día 360 del año
assert(addTicket(museum, 360, "John") == 1);
// Falla porque el día del año es igual a 0
assert(addTicket(museum, 0, "Katherine") == 0);
// Falla porque el día del año es mayor a 366
assert(addTicket(museum, 367, "Katherine") == 0);
// Se registra un ticket para que Paul visite el museo el día 4 del año
// Y retorna 2 porque es la cantidad de tickets para ese día
printf("%d\n\n\n", addTicket(museum, 4, "Paul"));
assert(addTicket(museum, 4, "Paul") == 2);
assert(addTicket(museum, 4, "Ariel") == 3);
}