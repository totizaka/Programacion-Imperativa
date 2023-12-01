#include <stdio.h>
#include "../Biblioteca/random.h"

int main(){
randomize();
int num, letra, txt, contador;

letra=randInt('A', 'Z');

num=randInt(1, 256);

for (int i = 0; (txt=getchar())!=EOF || i<num; i++)
{
    if (txt==letra || txt==(letra+('a'-'A')))
    {
        contador++;
    }
    
}

printf("%d\n%c\n%d",num,letra,contador);


    return 0;
}