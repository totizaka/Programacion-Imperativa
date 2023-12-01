#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

float num, parteDecimal;
int parteEntera, parteDecimal_Entera, cincosEntera=0, cincosDecimal=0;

num=getfloat("\ningresar numero positivo\n");

parteEntera=(int)num;

parteDecimal=(num-(int)num);


while ((parteEntera!=(int)parteDecimal))
{
    parteDecimal*=10;
}

parteDecimal_Entera=(int)parteDecimal;

for (; parteEntera > 0 && parteDecimal_Entera > 0; parteEntera/=10, parteDecimal_Entera/=10)
{
    if ((parteEntera%5)==0 && (parteEntera%10)!=0)
    {
        cincosEntera++;
    }
    if ((parteDecimal_Entera%5)==0 && (parteDecimal_Entera%10)!=0)
    {
        cincosDecimal++;
    }
}


printf("cantidad de cincos parte entera: %d\ncantidad de cincos parte decimal %d",cincosEntera, cincosDecimal);

    return 0;
}