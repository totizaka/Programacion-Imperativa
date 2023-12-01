#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

char num1, num2;

num1=getchar();
num2=getchar();

num1==num2 ? printf("\nEl caracter %c es igual al caracter %c\n",num1,num2) : (num1>num2 ? printf("\nEl caracter %c es mayor al caracter %c\n",num1,num2) : printf("\nEl caracter %c es menor al caracter %c\n",num1,num2));

return 0;
}