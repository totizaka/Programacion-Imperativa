#include <stdio.h>
#include "../Biblioteca/getnum.h"
#include <math.h>

double redondeo(double numero, int cifras){

int numaux, potenciaDiez=1;

for (int i=0; i<cifras ; i++)
{
    potenciaDiez*=10;
}
numaux=(numero*potenciaDiez);

numero=((double)numaux/potenciaDiez);

return numero;

}

int main(){

double num=redondeo(12.3456789,3);

printf("%f",num);

    return 0;
}
