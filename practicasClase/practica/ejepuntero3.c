#include <stdio.h>
#include <ctype.h>

int longString( const char *s){

int cant=0;

while ( *s != 0)
{
    s++;
    cant++;
}
    return cant;
}


int belongs( const char *s, char c){

while ( *s != 0 )
{
    if ( tolower(*s) == tolower(c) )
    {
        return 1;
    }
    
    s++;
}

    return 0; 
}

int main(){

char texto[] = "hola, soy ANDRES";

char c=',';

if (belongs(texto, c))
{
    printf("esta");
}


    return 0;
}