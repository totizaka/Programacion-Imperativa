#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

char* aMayusculas(char* s)
{
    char* t;

    for ( t=s; (*t = toupper(*t)); t++)
    {
    
    }
    return s;
    
}

void resize(char *p, unsigned int bytes) {
     p = realloc(p, bytes);
}

int 
main(void) {
    char *p=NULL;
    resize(p, 100);
    strcpy(p, "hello world");
    aMayusculas(p);
    printf("%s\n", p);

    return 0;

}
