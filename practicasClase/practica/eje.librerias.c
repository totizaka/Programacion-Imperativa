#include <stdio.h>
#include <ctype.h>
#include "../Getnum/getnum.h"

int main(){
    
int c;

while((c=getchar())!=EOF)
{
if (!isspace(c))
    putchar(toupper(c));
}
return 0;
}