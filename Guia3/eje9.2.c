#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

printf("escribir un texto");

int texto, space, caracter;

while((texto=getchar())!=EOF){

if(texto!=' ' && texto !='\t' && texto !='\n')
  printf("%c",texto);
  else
  printf("\n");
}

    return 0;
}