#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

int main()
{
    char *s, *aux;
	s = malloc(20);
	aux = realloc(s, 100);
	free(s);
	free(aux);
}