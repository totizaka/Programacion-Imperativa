#include <stdio.h>
#include <assert.h>
#include <string.h>

void eliminaBlancos(char *texto){

int j=1;

    for (int i = 1; texto[i]; i++)
    {
        if ((texto[i] !=' ' || texto[i-1] != ' '))
        {
            texto[j++]=texto[i];
        }
    }
    texto[j]=0;
}

// hola    hola.



int main(void) {
  char s[60] = "   "; // cant impar de blancos
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  strcpy(s,"  ");
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);
  
  strcpy(s," . . .  ");
  eliminaBlancos(s);
  assert(strcmp(s, " . . . ")==0);

  strcpy(s,"");
  eliminaBlancos(s);
  assert(strcmp(s, "")==0);

  strcpy(s,"sinblancos");
  eliminaBlancos(s);
  assert(strcmp(s, "sinblancos")==0);



  printf("OK!\n");
  return 0;
}