#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Biblioteca/random.h"
#include "../Getnum/getnum.h"

#define BORRA_BUFFER while (getchar() != '\n')
#define CANT_PALABRAS 11 
#define LARGO_MAX 20 
#define ERRORES_MAX 8 
#define CANT_LETRAS 26 


void generaEspacioAciertos(char *espacioPalabra, char palabra[])
{
    int i=0;

    printf("\nespacio de la palabra:\n");

    for (i = 0; palabra[i] != '\0'; i++)
    {
        espacioPalabra[i]='/';
        printf("%c", espacioPalabra[i]);
    }
    espacioPalabra[i]=0;
}

void generaAbecedario(char abecedario[])
{   
    printf("\nletras utilizables:\n");
    for (int i = 0; i < CANT_LETRAS; i++)
    {
        abecedario[i] = 97+i;
        printf("%c", abecedario[i]);
    }
}

char pedirLetra(char* abecedario, int* intentos)
{
    int letra;

    do
    {
        printf("\ningresar letra:\n");
        letra = getchar();

        (*intentos)++;

        if (abecedario[letra-97] == 'X')
        {
            printf("\nletra ya utilizada\n");
        }

        if ( letra != '\n')
        {
            BORRA_BUFFER;
        }
    }
    while (letra < 'a' || letra > 'z' || abecedario[letra-97] == 'X');

    abecedario[letra-97]='X';
    return letra;
}

int verificarLetra(char *palabra, char *aciertos, char letra)
{
    int esta=0;

    for (int i = 0; palabra[i] != '\0'; i++)
    {
        if (palabra[i] == letra)
        {
            aciertos[i] = palabra[i];
            esta++;
        }
    }
    return esta;
}

void imprimirAciertos(char *aciertos)
{
    printf("\nasi queda:\n");

    for (int i = 0; aciertos[i]!=0 ; i++)
    {
        printf("%c", aciertos[i]);
    }
    putchar('\n');
}


int main()
{
    randomize();

    int palabra, letra, aciertos=0, intentos = 0;

    char* lista[] = {"aeropuerto", "mercurio", "avion", "espacio", "empresa", "titular", "maradona", "salomon", "electricista", "zapato", "sol"};

    palabra = (randInt(1, CANT_PALABRAS)-1);

    // printf("la palabra que toco es %s\n", lista[palabra]);

    int dim = strlen(lista[palabra]);

    char espacioPalabra[LARGO_MAX];

    char abecedario[CANT_LETRAS];

    printf("Empieza el juego del ahorcado\n\n intentar adivinar la palabra utilizando solo letra del alfabeto ingles\n\n");

    generaEspacioAciertos(espacioPalabra, lista[palabra]);
    generaAbecedario(abecedario);

    for (int i=0; aciertos < dim && intentos < ERRORES_MAX; i++)
    {
        letra = pedirLetra(abecedario, &intentos);

        aciertos += verificarLetra(lista[palabra], espacioPalabra, letra);

        printf("\nla letra es: %c\nlos aciertos totales son: %d\n", letra, aciertos);

        imprimirAciertos(espacioPalabra);

        printf("letras no utilizadas:");

        for (int i = 0; i < CANT_LETRAS; i++)
        {
            printf("%c", abecedario[i]);
        }
    }
    if (aciertos == dim)
    {
        printf("\nFelicitaciones has ganado");
    }
    else
        printf("\nHas perdido");
    
}

