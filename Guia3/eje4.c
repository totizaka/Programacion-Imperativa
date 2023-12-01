#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

int x,z;

x=getint("ingresar num");
z=getint("ingresar num");


if (x == 1){
	if (z > 1)
		printf("x == 1 y z > 1");}
	else{
	if (x > 1)
		printf("x > 1");
	else
		printf("x < 1");}


return 0;
}