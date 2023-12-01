#include <stdio.h>                                                                   
 
#define DIM 20    

 typedef struct { 
    int a;    
    int b;  
} Coordenada;    

typedef Coordenada * PCoord;    

typedef struct  
{     
    char* nombre;     
    Coordenada punto1;     
    PCoord punto2;  
} TipoX;    

 int  
main(void)  {
TipoX var1;     
    var1.nombre = "nombre1";     
    var1.punto1.a = 10;      
    var1.punto1.b = 30;      
    var1.punto2->a = 20;      
    var1.punto2->b = 50;        
 
return 0;  
}  