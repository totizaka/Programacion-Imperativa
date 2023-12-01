#include <stdio.h>

#define ENT_HORA 8
#define ENT_MINUTOS 30




int 
llegaTemprano (const int hora, const int minutos)
{
    if ((hora < ENT_HORA))
    {
        return 1;
    }
    else if (hora == ENT_HORA)
    {
        if (minutos <= ENT_MINUTOS)
        {
            return 1;
        }
    }
    
        return 0;
}


int main() {

int hora=7, min=59;

if (llegaTemprano(hora, min) == 1)
{
    printf("llego temprano");
}
else{
    printf("llego tarde");}




    return 0;
}