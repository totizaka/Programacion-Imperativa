#include <stdio.h>
#define MAX 28

static int bisiesto(int anio) {
    int esb=0;

    if((anio%4 == 0 && anio%100!= 0) || anio%400 == 0)
        esb=1;
    return esb;
}


int unDiaMas(int *dia, int *mes, int *anio){

    int daytab[2][12] = {{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};

if (bisiesto(*anio))
{
    if ( *dia <= MAX )
    {
        *dia + 1;
    }
    else if ( *dia >= daytab[1][*mes] )
    {
        if ( *mes == 12 )
        {
            *dia=1;
            *mes=0;
            *anio++;
        }
        *mes+1;
    }
}
else
{
    if ( *dia <= MAX-1 )
    {
        *dia + 1;
    }
    else if ( *dia >= daytab[0][*mes] )
    {
        if ( *mes == 12 )
        {
            *dia=1;
            *mes=0;
            *anio++;
        }
        *mes+1;
    }
}


    return 0;
}