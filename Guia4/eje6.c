#include <stdio.h>
#define MAXIMO2(x,y,z) (z = ((x) > (y) ? (x) : (y)))

#define MAXIMO3(x, y, z, d) (d = ( MAXIMO2(x, y, d) < (z) ? (z) : d ))

int main(){

int num1=5, num2=20, num3=50, resp;

MAXIMO3(num1, num2, num3, resp);

printf("%d",resp);

    return 0;
}