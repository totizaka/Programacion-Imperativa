#include <stdio.h>

char * strcopy(char *t, char*s){

char *aux = t;

while (*s != 0)
{
    *aux++ = *s++;
}
    return t;
}



char * strncopy(char *t, char*s, int n){

char *aux = t;

for (int i = 0; i < n; i++, aux++)
{
    if (*s != 0)
    {
        *aux = *s++;
    }
    else
        *aux=0;
}

    return t;
}




char * strcatt(char *t, char*s){

char *aux = t;

while (*aux!=0)
{
    aux++;
}

while (*s!=0)
{
    *aux++=*s++;
}
*aux=0;

    return t;
}






char * strcomp(char *t, char*s){

int resp;

while ( *t == *s && (*t != 0 || *s!=0))
{
    t++;
    s++;
}

if (*t==0 & *s==0)
{
    resp = 0;
}
else if (*t > *s)
{
    resp = 1;
}
else
    resp = -1;    

return resp;
}