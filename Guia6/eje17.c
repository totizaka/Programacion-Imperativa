#include <stdio.h>
#include <assert.h>
#include <math.h>

#define M 5
#define N 4

int armaFilas(int vec[][M], int resp[]){

int suma=0, col=M, dim=0, aux=0, cant=0;

    for (int i = 0; i < N; i++)
    {   
        suma=0;
        aux=0;

        for (int j = 0; j < M; j++)
        {
            if (vec[i][j] < 10 && vec[i][j] >=0)
            {
                suma+=((vec[i][j])*pow(10,(col-1)));
                aux++;
            }
            col--;
        }

        col=M;

        if (aux==col)
        {
            resp[cant]=suma;
            dim++;
            cant++;
        }
    }
    return dim;
}


int armaFilas(int mat[][M], int vec[]);


int main(void)
{
     int m1[N][M] = { { 1,2,3,4,5},
                { 1,2,13,4,5},
                { 1,2,4,4,5},
                { 1,2,-3,4,5}};
    int vec[N];
    int n = armaFilas(m1, vec);
    assert(n==2);
    assert(vec[0]==12345);
    assert(vec[1]==12445);

    int m2[N][M] = { { 1,0,3,4,5},
                { 0,2,1,4,5},
                { 9,9,9,9,9},
                { 0,0,1,4,5}};
     n = armaFilas(m2, vec);
    assert(n==4);
    assert(vec[0]==10345);
    assert(vec[1]==2145);
    assert(vec[2]==99999);
    assert(vec[3]==145);


    int m3[N][M] = { { 11,0,3,4,5},
                { 0,2,1,14,5},
                { 9,9,9,91,9},
                { 0,0,1,14,5}};
     n = armaFilas(m3, vec);
    assert(n==0);
    

    printf("OK!\n");
    return 0;
}