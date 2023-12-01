#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Getnum/getnum.h"

int MultCifra(int num, int cifra, int baseE)
{
    int resp = ((num/(pow(10, (cifra-1)))) * pow(baseE, cifra-1));

    return resp;
}

int RestoCifra(int num, int cifra)
{
    num = (num/(pow(10, (cifra-1))));

    num = num * pow(10, (cifra-1));

    return num;
}

int CambioA_Base10 (int num, int baseE)
{
    int numaux=num, cifra=0;

    while (numaux >= 1)
    {
        numaux=numaux/10;
        cifra++;
    }
    
    numaux=0;

    while (cifra>0)
    {
        numaux += MultCifra(num, cifra, baseE);

        num = num - RestoCifra(num, cifra);

        cifra--;
    }
    
    return numaux;
}



int main(){

// int correcto, baseE, baseS, numaux, numb10;

// printf("ingresar <base de entrada> y base de salida");

// scanf("<%d>%d", &baseE, &baseS);

// int num = getint("ingresar numero en la base indicada");

int num=getint("ingresar numero");
int base=getint("ingresar base");

int num2 = CambioA_Base10(num, base);

printf("%d\n%d", num, num2);

return 0;
}