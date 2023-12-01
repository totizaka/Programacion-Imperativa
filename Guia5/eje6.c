#include <stdio.h>
#include "../Biblioteca/getnum.h"

int minMayus(int letra){

if (letra>='A' && letra<='z')
{
    if (letra>='a')
    {
        letra-=('a'-'A');
    }
}
    return letra;
}

int mayMinus(int letra){

if (letra>='A' && letra<='z')
{
    if (letra<'a')
    {
        letra+=('a'-'A');
    }
}
    return letra;
}

int carSig(int letra){

    letra=(letra+1);
    return letra;
}

int letSig(int letra){

if (letra>='A' && letra<='z')
{
    if (letra==('z'))
    {
        letra='a';
    }
    else if (letra==('Z'))
    {
        letra='A';
    }
    else
    {
        letra=(letra+1);
    }
}
    return letra;
}

int menu(){

    int opciones;
    opciones=getint("elegir opcion:\n1. mayus a minus\n2. minus a mayus\n3. caracter siguiente\n4. letra siguiente\n");

    return opciones;
}

int main(){

int txt, opcion, caracter;

do 
{   
    printf("ingresar caracter\n");
    (txt=getchar());

    opcion=menu();

    switch (opcion)
    {
        case 1:
            caracter=mayMinus(txt);
            break;
        
        case 2:
            caracter=minMayus(txt);
            break;

        case 3:
            caracter=carSig(txt);
            break;
        
        case 4:
            caracter=letSig(txt);
            break;
    }

printf("%c\n",caracter);
}
while (txt!=EOF);

    return 0;
}