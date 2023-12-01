#include <stdio.h>
#include <string.h>
#include <assert.h>

int copiaSubVector(char arregloIn[], char arregloOut[], int desde, int hasta, int dimMax)
{
    int dimArregloIn = strlen(arregloIn);

    if (desde < 0 && desde > dimArregloIn && desde>hasta && dimMax<=0)
    {
        return 0;
    }
    
    int i=0;

    for (; desde <= hasta && desde < dimMax-1 && arregloIn[i]!=0; desde++)
    {
        arregloOut[i++] = arregloIn[desde];
    }
    
        arregloOut[i]=0;

return i;
}


int main(void) {
  char s[100];
  assert(copiaSubVector("un texto", s,0,0,1)==0);

  assert(strcmp(s, "")==0);
  assert(copiaSubVector("un texto", s,0,0,10)==1);

  assert(strcmp(s, "u")==0);
  assert(copiaSubVector("un texto", s,0,10,1)==0);

  assert(strcmp(s, "")==0);

  assert(copiaSubVector("un texto", s,45,130,1)==0);


  assert(copiaSubVector("un texto", s,0,130,2)==1);
  assert(strcmp(s, "u")==0);

  assert(copiaSubVector("un texto", s,0,130,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,0,7,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,0,7,9)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,2,5,8)==4);
  assert(strcmp(s, " tex")==0);
  
  assert(copiaSubVector("un texto", s,45000,130000,10)==0);

  printf("OK!\n");
  return 0;
}