#include <stdlib.h>
#include <stdio.h>

int
main(void) {

        // char * p = malloc(10);

        char p[11];

        for(int i=0; i <= 10; i++)
                p[i] = i * 10;


        for(int i=0; i <= 10; i++)
                printf("%d\n", p[i]);

        return 0;
}
