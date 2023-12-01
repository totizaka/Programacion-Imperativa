#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void regla(int h)
{
    if (h==1)
    {
        printf("1");
    }
    return regla(h/2);
    printf("%d",h);
    return regla(h/2);
}

//      1215121
//      121412191214121