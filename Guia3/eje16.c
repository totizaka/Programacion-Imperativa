#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

int num, posicion, binario;

    do
    {
        num=getint("ingresar numero positivo");
    } while (num<=0);
    
    for (binario = 0, posicion=1; num > 0; num/=2, posicion*=10)
    {
        if ((num%2)!=0)
            binario+=posicion;
    }
    
printf("en binario %d",binario);



    return 0;
}