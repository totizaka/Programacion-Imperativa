#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

char carac;

carac=getchar();

carac>='a' && carac<='z' ? printf("%c",carac-('a'-'A')) : printf(" no es una letra minuscula ");

return 0;
}
