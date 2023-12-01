#include <stdio.h>
#include <stdlib.h>

int palindromo(char* string, int dim)
{
    if (dim == 0)
    {
        return 1;
    }
    if (string[0] != string[dim-1])
    {
        return 0;
    }
    return (palindromo(string+1, dim-2));

}

int main()
{
    char* string = "lallal";
    int dim=6;

    int palind = palindromo(string, dim);

    printf("%d", palind);
}