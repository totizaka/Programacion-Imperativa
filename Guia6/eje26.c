#include <stdio.h>
#include <assert.h>
#include <string.h>

void insertaDesde(char *string1, char *string2, char car)
{
    char *pos;
    
    pos = strchr(string1, car);

    if (pos != NULL)
    {
        strcpy(pos, string2);
    }
}

int main(){

    char str1[20] = "manuel";
    char str2[] = "javi";
    insertaDesde(str1, str2,'n');
    printf("%s\n",str1); // muestra majavi
}