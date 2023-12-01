#include <stdio.h>
#define dims 10

int dondeEsta(int vec[], int dim, int num, int resp[]){

int r=0;

for (int i = 0; i < dim || vec[i]<=num; i++)
{
    if (vec[i]==num)
    {
        resp[r]=i;
        r++;
    }
}
return r;
}

int main(){

    int vec[dims] = {3, 5, 5, 5, 5, 6, 7, 7, 8, 9, 12, 15};


    return 0;
}
