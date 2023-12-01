#include <stdio.h>
#include <stdlib.h>

int suma(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return num%10 + suma(num/10);
}

int main()
{
    int num = 3498;

    printf("%d", suma(num));
}