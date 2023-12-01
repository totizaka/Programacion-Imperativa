#include <stdio.h>
#include <limits.h>

int
main(void) {

char car;
car=getchar();

if (car>='A' && car<='z')
{
    printf("%c es una letra",car);}
else {
    printf("%c no es una letra",car);
}


return 0;
}