#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

int a, mult, fact=1, contador;
float e=1;

for ( a = 0, mult=0, contador=1; a< 10; a++, mult++, contador++)
{
    if (a!=0)
    {
        fact*=mult;
        e+=(1/(float)fact);
    }
    else
        printf("N\te\n");
    printf("%d\t%f\n",contador,e);
}




    return 0;
}