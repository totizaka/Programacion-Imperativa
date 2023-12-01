#include <stdio.h>
#include "../Getnum/getnum.h"

int
main(void) {

    float sum;
    do
    {
        sum=getfloat("\ningresar suma de venta ");
    } while (sum<0);
    
    if (sum>4000)
    {printf("\nel monto a cobrar es $%10.2f",300+(sum*(0.09))); }

    if (sum<=4000 && sum>2000)
    {printf("\nel monto a cobrar es $%10.2f",300+(sum*(0.07))); }

    if (sum<=2000 && sum>1000)
    {printf("\nel monto a cobrar es $%10.2f",300+(sum*(0.05))); }

    if (sum<=1000)
    {printf("\nel monto a cobrar es $%10.2f",300+(sum*(0.00))); }

return 0;
}