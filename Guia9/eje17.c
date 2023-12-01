#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int bienFormado(char* string)
{
    if (*string == '\0') 
    {
        return 0;
    }
    if ((isdigit(*string) && *string != '0') && (isdigit(*(string+1)) && *(string+1) != '0'))
    {
        return -10;
    }
    else if (isalpha(*string))
    {
        return (-1 + bienFormado(string+1));
    }
    else if (isdigit(*string))
    {
        return ((*string-48) + bienFormado(string+1));
    }   
    return 1;
}

// int main()
// {
//     char* vec = "abcd4a1";

//     printf("%d\t %d",bienFormado(vec), vec[4]);
// }

int main(void) {
 char * zero[]={"abcd4a10bb2", "", "0000", "a1", "abc3", "0a1"};

  char * not_zero[] ={ "a", "1", "a2", "abc2", "abc4", "abc33", "0123",  "$1", "@@2", "abcd22", "@@"};

  for(int i=0; i < sizeof(zero)/sizeof(zero[0]);i++) {
    printf("%s\n", zero[i]);
    assert(bienFormado(zero[i])==0);
  }    

  for(int i=0; i < sizeof(not_zero)/sizeof(not_zero[0]);i++) {
    printf("%s\n", not_zero[i]);
    assert(bienFormado(not_zero[i]) !=0);
 }

  puts("OK!");
  return 0;
}