#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"


int main()
{
    static float  tabla[2][3] = {  { 1.1, 1.2, 1.3 }, { 2.1, 2.2, 2.3 } };

    printf("%f",tabla);
    printf("%f",tabla+1);
    printf("%f",*(tabla + 1));
    printf("%f",*(tabla + 1) + 1 );
    printf("%f",*tabla + 1 );
    printf("%f",*(*(tabla + 1) + 1) );
    printf("%f",*(*tabla + 1) );
    printf("%f",*(*(tabla + 1)));

}