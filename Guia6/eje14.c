#include <stdio.h>
#include <assert.h>

int contieneaux( int vec1[], int dim1, int vec2[], int dim2 ){

int cant=0;

for (int i = 0; i < dim1; i++)
{   
    for (int j = 0; j < dim2 && cant<=i; j++)
    {
        if ( vec1[i] == vec2[j] )
        {
            cant++;
        }
    }
}

if (cant == dim1)
{
    return 1;
}
    return 0;
}



int contiene( int vec1[], int dim1, int vec2[], int dim2){

int vec1ENvec2= contieneaux(vec1, dim1, vec2, dim2);
int vec2ENvec1= contieneaux(vec2, dim2, vec1, dim1);

if (vec1ENvec2 == 1 && vec2ENvec1 == 1)
{
    return 1;
}
else if (vec1ENvec2 > vec2ENvec1)
{
    return 1;
}
else if ( vec1ENvec2 < vec2ENvec1)
{
    return 2;
}
else
    return 0;
}

int main(void) {

  int v1[] = {1,6,5,3,2};
  int v2[] = {1,2};
  assert(contiene(v1, 5, v2, 2)==2);
  assert(contiene(v2, 2, v1, 5)==1);
  assert(contiene(v1, 1, v2, 2)==1);
  assert(contiene(v1, 0, v2, 2)==1);
  assert(contiene(v1, 5, v2, 0)==2);
  
  int v3[] = {1,2,3,4,5,6};
  assert(contiene(v1, 5, v3, 6)==1);

  int cnt = contiene(v1, 0, v3, 0);
  assert(cnt ==1 || cnt==2);

  int v4[] = { 10, 20, 30, 1, 2};
  assert(contiene(v2, 2, v4, 4)==0);
  assert(contiene(v2, 2, v4, 5)==1);
  assert(contiene(v4, 5, v2, 2)==2);

  int v5[] = {1,1,1,1,1,2,1,2};
  int v6[] = {1,2,3};
  assert(contiene(v5, 8, v6, 3)==1);
  assert(contiene(v6, 3, v5, 8 )==2);

  printf("OK!\n");
  return 0;
}