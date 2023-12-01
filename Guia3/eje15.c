#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

int numBin, base, decimal=0;

    numBin=getint("ingresar numero binario positivo");
    
    for ( base=1 ; numBin > 0; numBin/=10, base*=2)
    {
        if ((numBin%10)>1)
        {
        printf("no es binario");
        return 0;
        }
        else if ((numBin%10)==1)
        {
        decimal+=base;
        }
        
    }
    
printf("en decimal es %d",decimal);
    

return 0;
}