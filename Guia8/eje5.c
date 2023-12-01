#include <stdio.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

typedef struct 
    {
        int x, y;
    }tipoPunto;

void movimiento(tipoPunto* particula)
{
    int direccion = randInt(1,4);

    switch (direccion)
    {
    case 1:
        (*particula).x--;
        break;
    case 2:
        (*particula).x++;
        break;
    case 3:
        (*particula).y--;
        break;
    case 4:
        (*particula).y++;
        break;
    }
}

int seSale(tipoPunto particula, int radio)
{
    if ((particula.x) * (particula.x) + (particula.y) * (particula.y) >= radio*radio)
    {
        return 0;
    }
    return 1;
}

int main()
{   
    randomize();

    unsigned int tiempo;

    tipoPunto particula;

    int radio = 2;

    for (int i = radio; i <= 100; i*=radio)
    {
        tiempo=0;
        particula.x = 0;
        particula.y =0;

        do
        {
            movimiento(&particula);
            tiempo++;
        } while (seSale(particula, i));

        printf("radio:\ttiempo:\trelacion:\n");

        printf("%d\t%d\t%.2f\n", i, tiempo, (float)i/(float)tiempo);

    }
}