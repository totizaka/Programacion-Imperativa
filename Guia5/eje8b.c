#include <stdio.h>
#include "../Biblioteca/getnum.h"
#include <math.h>

int menu(){

    int opciones;
        opciones=getint("elegir opcion:\n1. redondeo a entero mas cercano\n2. redondeo a la decima mas cercana\n3. redondeo a la centecima mas cercana\n4. redondeo a la milesima mas cercana\n");

    return opciones;
}

double redondeo(double numero, int cifras){

int factor=1;

    for (int i = 0; i < cifras; i++)
    {
        factor*=10;
    }
    
    return floor(numero * factor + 0.5)/factor;
    
}

int main(){

double numero=getdouble("ingresar numero");

int opcion=menu();

switch (opcion)
{
case 1:
    numero=redondeo(numero,0);
    break;

case 2:
    numero=redondeo(numero,1);
    break;

case 3:
    numero=redondeo(numero,2);
    break;

case 4:
    numero=redondeo(numero,3);
    break;
}
printf("%f",numero);

    return 0;
}