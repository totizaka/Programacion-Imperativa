#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

int main()
{
    char *p[2][3] =  {{"abc","defg","hi"},{"jklmn","pqrstuvw","xyz"}};

    printf("%c",***p);                  //p[0][0][0]

    printf("%c",**p[1]);                //p[1][0][0]

    printf("%c",**(p[1]+2));            //p[1][2][0]

    // printf("%c",*(*(p+1)+1)[7]);     //

    printf("%c",*(p[1][2]+2));          //p[1][2][2]



}
