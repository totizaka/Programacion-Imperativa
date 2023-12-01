#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

char carac;

carac=getchar();

carac>='A' && carac<='z' ? printf("%c esto es una letra", carac) : printf("%c esto no es una letra ",carac);


    return 0;
}