#include  <stdio.h>
#include <math.h>

int diferencia(int const vec[]){

int diferencia = 0;

if (vec[0] != 0)
{
for (int i = 1; vec[i]!=0; i++)
{   
    int valor = fabs((vec[i-1]) - (vec[i]));

    if (diferencia < valor)
    {
        diferencia = valor;        
    }
}
}
    return diferencia;
}

int main(){

int vec[]={0};

printf("%d",diferencia(vec));

    return 0;
}