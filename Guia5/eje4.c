#include <stdio.h>
#include "../Biblioteca/random.h"
#include "../Biblioteca/getnum.h"

int numAleatorio(int num1, int num2){

int numAleatorio;
randomize();

return numAleatorio=randInt(num1, num2);

}


int main(){

int num;
num=numAleatorio(3,10);
printf("%d",num);

    return 0;
}