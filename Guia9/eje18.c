#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int sumMach(int vec[])
{
    if (vec[0] == -1)
        return 0;

    //VOY HASTA EL FINAL
    //EMPIEZO A IR PARA ATRAS
    //EL PRIMERO DEVUELVO SUMANDO
    //VOY RESTANDO HASTA LLEGAR A CERO Y VUELVO A SUMAR
    //SI ME DIO NEGATIVO, YA PERDI

    int actual = sumMach(vec+1);

    if(actual == 0)
        actual = vec[0];
    else if(actual > 0)
        actual -= vec[0];
    
    return actual;
}
