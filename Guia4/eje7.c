#include <stdio.h>
#include "../Getnum/getnum.h"

#define isdigit(x) (x >= '0' && x <='9' ? 1 : 0)

int main(){

int letra;
	letra = getchar();
	if ( isdigit(letra) )
		printf("Es un dígito\n");


    return 0;
}