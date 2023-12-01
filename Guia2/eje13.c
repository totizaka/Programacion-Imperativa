#include <stdio.h>
#include "../Getnum/getnum.h"

int main(){

int num1, num2;

num1=getint(" ing numero ");
num2=getint(" ing numero ");


(num2%num1)==0 ? printf("%d es multiplo",num2) : printf("%d no es multipplo",num2);

    return 0;
}