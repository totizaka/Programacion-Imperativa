#include <stdio.h>
#include "../Getnum/getnum.h"
#include <ctype.h>
#include <stdlib.h>


int main(){

int a, b, c;
a = getchar();
b = getchar();
c = getchar();


if (a>='A' && a<='Z' && a!='A' && a!='E' && a!='I' && a!='O' && a!='U')
	printf("El caracter %c es una consonante mayúscula \n", a);
else 
    if (a>='a' && a<='z' && a!='a' && a!='e' && a!='i' && a!='o' && a!='u')
		printf("El caracter %c es una consonante minúscula \n", a);
    else 
 		if (a>='A' && a<= 'z')
			printf("El caracter %c es una vocal \n", a);
		else{
			printf("El caracter %c no es una letra \n", a);}


if (b % 2 == 0){
    printf("El valor ASCII de %c es par \n", b);}
	
if (b>='2' && b<='8' && b!='3' && b!='5' && b!='7')
printf("El caracter %c representa un dígito par \n", b);
	
if ((c>='A' && c<='Z') || c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
printf("El caracter %c es una vocal o es mayúscula \n", c);
	
if (c>='A' && c<='z' && c!='a' && c!='A' && c!= 'e' && c!='E'
    && c!='i' && c!='I' && c!='o' && c!='O' && c!='u' && c!='U')
printf("El caracter %c no es una vocal pero es letra \n", c);


return 0;
}
