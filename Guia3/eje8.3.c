#include <stdio.h>
#include "../Getnum/getnum.h"

int main(void) {
   int lim = getint("Ingrese límite:"), c;

   for(int i=0; (i<lim-1) ? ((c=getchar()) != '\n') ? (c != EOF) : 0 : 0; ++i){

      putchar(c);
   }
   return 0;
}
