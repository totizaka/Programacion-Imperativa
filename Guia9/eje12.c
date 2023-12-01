#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int balance(char* string)
{
    if (*string == '\0')
    {
        return 0;
    }
    if (*string == '(')
    {
        return 1 + balance(string+1);
    }
    if (*string == ')')
    {
        return -1 + balance(string+1);
    }
    return balance(string+1);
}


int main(void) {

  assert(balance("")==0);
  assert(balance("((()))")==0);
  assert(balance(")(")==0);
  assert(balance("()()")==0);
  assert(balance(")))(((")==0);
  assert(balance("))) ((( ))( ()() ()()(")==0);
  
  assert(balance(")")!=0);
  assert(balance("(")!=0);
  assert(balance(")()")!=0);
  assert(balance(" ) ")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

  printf ("OK!\n");
  return 0;
}