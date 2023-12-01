#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char* strrchrRec(const char* texto, char c)
{   
    if (*texto == '\0')
    {
        return NULL;
    }
    if (*texto == c)
    {   
        return texto;
        exit;
    }
    strrchrRec(texto+1, c);
}

int
main(void) {
	char * s = "vamos a buscar";

	// for ( int i=0; s[i]; i++) {
	// 	assert(strrchr(s, s[i]) == strrchrRec(s, s[i]));
	// } 

    printf("%s", strrchrRec(s, 'a'));

	puts("OK!");
}