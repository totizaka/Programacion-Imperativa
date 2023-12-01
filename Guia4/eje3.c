#include <stdio.h>

#define VOLUMEN(x) ((1.33) * (3.14) * (x*x*x))

int main(){

int num, vol;

num=getint("ingresar radio");

vol=VOLUMEN(num);

printf("%d",vol);
    return 0;
}