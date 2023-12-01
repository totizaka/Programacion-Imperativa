#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int orden(int* vec)
{
    if (vec[0] == -1 || vec[1] == -1)
    {
        return 0;
    }
    
    if (vec[2] == -1)
    {
        if (vec[0] < vec[1])
        {
            return 1;
        }
        else if (vec[0] > vec[1])
        {
            return -1;
        }
        return 0;
    }
    
    int ordenResto = orden(vec+1);
    
    if (ordenResto == 0)
    {
        return 0;
    }
    else if (ordenResto == 1)
    {
        return vec[0] < vec[1];
    }
    else if (vec[0] > vec[1])
    {
        return -1;
    }
    return 0;
}