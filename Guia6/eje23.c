#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uInt ;

#define TRUE 1
#define FALSE !TRUE


static int valFormato( const char * fecha)              /* Función auxiliar que verifica que un string sea de la forma dd/mm/yyyy */
{
	int resp = TRUE, i;

	resp = (fecha[2] == '/' && fecha[5] == '/' && strlen(fecha)==10 );  /* Validamos primero la longitud y los separadores */

	if ( resp )                                                         /* Validamos ahora que el resto sean digitos */
	{
        for (i = 0 ; fecha[i] && resp; i++)
		{
            if ( i != 2 && i !=5 && !isdigit(fecha[i]))
			{	
                resp = FALSE;
            }
        }
    }
	return resp;
}

int esBisiesto(uInt anio) 
{
	return ( (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0 );
}



static int extraeFecha( const char * fecha, uInt *dia, uInt *mes, uInt *anio)   //Funcion auxiliar que extrae el dia, mes y año 
{                                                                               //de un string con el formato dd/mm/yyyy ya validado
                                                                                
static int diasMes[][12] =  {{31,28,31,30,31,30,31,31,30,31,30,31},              //vector para anio no bisiesto
 						    {31,29,31,30,31,30,31,31,30,31,30,31}};                 //vector para bisiesto

int fechaOK = FALSE;

	*dia = atoi(fecha);
	*mes = atoi(fecha + 3);
	*anio = atoi(fecha + 6);

	if ( *dia > 0 && *mes >= 1 && *mes <= 12)
	{
        fechaOK = *dia <= diasMes[esBisiesto(*anio)][*mes-1] ;
    }

	return fechaOK;
}


int valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio)
{
	int fechaOK;
	uInt lDia, lMes, lAnio;

   fechaOK = valFormato(fecha) && extraeFecha(fecha,&lDia,&lMes,&lAnio);

	if ( fechaOK) 
    {
		*dia  = lDia;
		*mes  = lMes;
		*anio = lAnio;
	}

	return fechaOK;	
}