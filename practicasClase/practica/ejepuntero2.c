int aparece(const int vec[], int num, int dim){

int *punt = vec + dim;

for (; vec < punt; vec++)
{
    if (*punt==num)
    {
        return 1;
    }
    
}
return 0;
}