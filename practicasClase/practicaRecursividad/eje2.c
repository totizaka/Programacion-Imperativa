int potencia(int base, int exponente)
{
    // if (base == 0)
    // {
    //     return 0;
    // }
    if (exponente == 0)
    {
        return 1;
    }
    // else if (exponente == 1)
    // {
    //     return base;
    // }
    return (base * potencia(base, exponente-1));
}