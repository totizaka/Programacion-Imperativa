#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

int num1, num2, op;

num1=getint(" ing numero ");
num2=getint(" ing numero ");

printf(" el promedio es %3.1f\n",(num1+num2)/(float)2);
printf(" la suma es %d\n ", num1+num2);
printf(" el mayor es %d\n ",num1>num2 ? num1 : num2);
printf(" el menor es %d\n ",num1<num2 ? num1 : num2);

num1==num2 ? printf("son iguales\n") : printf("no son iguales\n");

    return 0;
}