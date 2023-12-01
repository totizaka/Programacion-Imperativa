#include <stdio.h>
#define MAXIMO2(x,y,z) (z = ((x) > (y) ? (x) : (y)))

int main(){

int num=5, num2=20, resp;

MAXIMO2(num,num2,resp);

printf("%d",resp);

    return 0;
}