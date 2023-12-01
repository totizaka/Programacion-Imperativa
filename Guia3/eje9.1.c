#include <stdio.h>
#include "../Getnum/getnum.h"
#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'

int main (){

int countert =0, counters=0, countern=0, texto;

printf("ingresar texto");
while(( texto=getchar()) != EOF){

    if(texto==SPACE){
        counters+=1;}
    if(texto==TAB){
        countert+=1;}
    if(texto==NEWLINE){
        countern+=1;}
}
printf("\n cantidad de espacios: %d \n cantidad de tabs: %d \n cantidad de newlines: %d",counters,countert,countern);

    return 0;
}