#include <stdio.h>
#define MAX 10

int eliminaCeros(int v[], int n, int dest[]){

    int i=0, j=0;

    while (i<n)
    {
        if (v[i]!=0)
        {
            dest[j]=v[i];
            j++;
        }
        i++;
    }
    return j;
}

int main(){

    int orig[]={1,0,0,3,0,0,2,0,4};

    int dest[MAX];

    int dimDest=eliminaCeros(orig,sizeof(orig)/sizeof(orig[0]),dest);

    printf("%d",dimDest);
}