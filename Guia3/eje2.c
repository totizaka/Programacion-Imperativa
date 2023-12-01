#include <stdio.h>
#include <limits.h>

int
main(void) {

    char car1, car2;

    car1=getchar();
    car2=getchar();

    if (car1==car2)
    {
        printf("el caracter %c es igual al caracter %c",car1,car2);
    }
    else{
        if (car1>car2)
        {
            printf("el caracter %c es mayor al carcater %c",car1,car2);
        }
        else{
            printf("el caracter %c es menor al caracter %c",car1,car2);
        }
    }

return 0;
}