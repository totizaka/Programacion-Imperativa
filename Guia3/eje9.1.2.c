#include <stdio.h>
int main(void){

int text, space=0, tab=0, newline=0;

printf("ingresar texto");

while ((text=getchar())!=EOF)
{
    switch(text){

        case ' ' :
        space++;
        break;

        case '\t' :
        tab++;
        break;

        case '\n':
        newline++;
        break;
}
}
printf("cantidad de espacios: %d\ncantidad de tabs: %d\ncantidad de newlines: %d",space,tab,newline);


return 0;
}