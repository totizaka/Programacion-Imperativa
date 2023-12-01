#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

float farh, cels, grad;


do
{
cels=getfloat("Ingresar grado celsius");
} while (cels<=-20 || cels>=300);


farh=((cels*1.8)+32);

printf("cant de grados farenheit: %.2f",farh);

return 0;
}

