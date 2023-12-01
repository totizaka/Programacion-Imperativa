#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

    int txt, menor='z', menorMayus='z', menorMin='z', sumMayus=0, sumMinus=0;

    while ((txt=getchar())!=EOF)
    {
        if (txt>='A' && txt<='Z') //Si es mayuscula
        {
            sumMayus+=1;
            if (menorMayus>txt)
                menorMayus=txt;
        }
        else if (txt>='a' && txt<='z') //Si es minuscula
        {
            sumMinus+=1;
            if (menorMin>txt)
                menorMin=txt;
        } else if (txt != ' ')
        {
            break;
        }
        
    }

    if (menorMayus==(menorMin-('a'-'A'))){
        menor=menorMin;
    }
    else if (menorMayus>(menorMin-('a'-'A'))){
        menor=menorMin;
    }
    else
        menor=menorMayus; 

        


    

printf("cant mayus %d\n",sumMayus);
printf("cant minus %d\n",sumMinus);
printf("menor mayusc %c\n",menorMayus);
printf("menor minusc %c\n",menorMin);
printf("menor es %c\n",menor);
    return 0;
}
