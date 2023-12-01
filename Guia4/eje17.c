#include <stdio.h>
#include "../Getnum/getnum.h"

#define ELAPSED(x, y, z, w) ((((x)*60 + y) - ((z)*60 + w)) >= 0 ? (((x)*60 + y) - ((z)*60 + w)) : (((x)*60 + y) - ((z)*60 + w)) * (-1))

int main(){

int minutos, h1, h2, m1, m2;

h1 = 2; m1 = 10; h2 = 3; m2 = 15;

minutos = ELAPSED(h1, m1, h2, m2);	
printf("%d\n",minutos);

minutos = ELAPSED(3, 15, 2, 10);		
printf("%d\n",minutos);

minutos = ELAPSED(h1, m1, h1 + 1, m1);
printf("%d\n",minutos);

    return 0;
}