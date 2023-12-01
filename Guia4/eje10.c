#include <stdio.h>

int 
dcm (int a, int b)
{
	int auxi;

	while (auxi>0)
	{	
		auxi = a-b;
        b = auxi;
        auxi = a % b ;
}


	return a;
}

int main(){

int num1=35, num2=55, mcd;

mcd=dcm(num1,num2);

printf("%d",mcd);
    return 0;
}