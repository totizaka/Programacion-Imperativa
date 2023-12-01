#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int esPotenciaDe3(int num)
{
    if (num < 1)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else if (num % 3 != 0)
    {
        return 0;
    }
    return esPotenciaDe3(num/3);
}

 
int
main(void) {
    assert(esPotenciaDe3(0) == 0);
    assert(esPotenciaDe3(1) == 1);
    assert(esPotenciaDe3(3) == 1);
    assert(esPotenciaDe3(9) == 1);
    assert(esPotenciaDe3(27) == 1);
    assert(esPotenciaDe3(30) == 0);
    assert(esPotenciaDe3(100) == 0);
    printf("OK!\n");
    return 0;
}