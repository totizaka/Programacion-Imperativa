#include <stdio.h>
#include <string.h>
#include <assert.h>


// int aparece(char c, char * s, int pos){
//     int encontrado = 0;
//     for(int i = pos+1; s[i] != '\0' && !encontrado; i++){
//         if(s[i] == c)
//             encontrado++;
//     }
//     return encontrado;
// }

// void elimina(char s[]){
//     int j = 0;
//     for(int i = 0; s[i] != '\0'; i++){
//         if(!aparece(s[i],s,i))
//               s[j++] = s[i];
//     }

// }




// // int dimension(int ancho, int largo)
// // {
// //     int x='X', a='A', b='B', c='C';
// //     if (ancho<6 && largo<6)
// //     {
// //         return x;
// //     }
// //     else if (ancho>=6 && ancho<9 && largo>=6 && largo<9)
// //     {
// //         return a;
// //     }
// //     else if (ancho>=9 && ancho<15 && largo>=9 && largo<15)
// //     {
// //         return b;
// //     }
// // return c;

// // }








// // void billete(int cant)
// // {
// //     int vec[7]={100,50,20,10,5,2,1}, cantaux;

// //     if (cant>0)
// //     {
// //         for (int i = 0; i < 7; i++)
// //         {
// //             cantaux = (cant/vec[i]);

// //             cant -= (cant/vec[i])*vec[i];

// //             if (cantaux>0)
// //             printf("%d billete%s de %d\n", cantaux, cantaux > 1 ? "s" : "", vec[i]);
// //         }
// //     }     
// //     return;
// // }








// // #include <stdio.h>

// // #define CHANGE_CASE(car) (car < 'A' ? car : car <= 'Z' ? car + ('a' - 'A') : (car >= 'a' && car <= 'z') ? car - ('a' - 'A') : car)







// int elimina(int *s1,int *s2,int *s3)
// {
//     int i = 0, j = 0, fin2 = 0, fin3 = 0, i2 = 0, i3 = 0;

//     while (s1[i] != '\0' && (s2[i2] != '\0' || s3[i3] != '\0'))
//     {
//         fin2 = (s2[i2] == 0);
//         fin3 = (s3[i3] == 0);    

//         if (!fin2 && s1[i] == s2[i2])
//         {
//             i++;i2++;i3++;
//         }
//         else if(!fin3 && s1[i] == s3[i3])
//         {
//             i++;i2++;i3++;
//         }
//         else if(s1[i])
//         {
//             s1[j++] = s1[i++];      

//             if (!fin2){
//                 i2++;
//             }

//             if (!fin3){
//             i2++;i3++;
//             }

//         }        
//     }
//     s1[j] = 0;
// }







// #define DIM 3
// #define N   6 


// int verificar ( int matriz[N][N]) 
// {
//   int i, j, comp; 
//   comp= submatriz ( matriz, 0, 0+DIM) ; //Si comparo todas con la primera qu eesta si o si totall si 1 es dist entonces salta
//     for ( i=0 ;i<N;i+=3) 
//     { 
//        for ( j=0 ;j<N;j+=3)
//           {
//         if ( comp != submatriz ( matriz, i ,  j ))
//                 return 0;  
//            }
//     }
//  return 1;      
// }



// // int submatriz (int matriz[N][N], int inicioi, int inicioj ) 
// // {
// //   int i, j, num, suma=0,  aux[3*N + 1]={0};
  
 
// //   for (i=inicioi; i<( inicioi +DIM);i++) 
// //   { 
// //     for (j=inicioj;j<(inicioj +DIM);j++) 
// //     { 
// //         num= matriz[i][j];
// //         if ( aux[num]|| num>(3*N)|| num<0)
// //             return 0;
// //         aux[num]=1;
// //         suma +=num;
// //     }
// //    }
// //   return suma; 
// // }





// // // int main(){

// // //     int m1[DIM][DIM] = {{10,3,2,3,8,7},
// // //                         {12,8,6,6,2,4},
// // //                         {4,7,5,5,12,10},
// // //                         {2,12,6,10,4,5},
// // //                         {5,10,3,7,2,9},
// // //                         {8,4,7,3,6,11}};


// // //     int m2[DIM][DIM] = {{1,3,2,3,8,5},
// // //                         {9,8,6,6,2,4},
// // //                         {4,7,5,5,9,3},
// // //                         {2,9,6,1,4,5},
// // //                         {5,1,3,7,2,8},
// // //                         {8,4,7,3,6,9}};

// // //     assert(verifica(m1)==1);

    







// // //     puts("K");
// // // }





// // #define COLS 5
// // #define FILS 6

// // int wordle(char * secret, char m[FILS][COLS], int attempts, char colores[FILS][COLS])
// // {    
// //     int filaEncontrada = 0;
    
// //     for (int f = 0; f < attempts; f++)
// //     {
// //         if (strcmp(m[f], secret) == 0)
// //         {
// //             filaEncontrada = f; 
// //         }           
// //     }      
    
// //     for (int i = 0; i < filaEncontrada+1; i++)
// //     {
// //         for(int j = 0; j < COLS; j++)
// //         {
// //             if (m[i][j] == secret[j])
// //             {
// //                 colores[i][j] = 'V';
// //             }
// //             else if (strchr(m[i],secret[j]) != NULL)
// //             {
// //                 colores[i][j] = 'A';
// //             }
// //             else
// //             {
// //                 colores[i][j] = 'G';
// //             }    
// //         }
// //     }

// //     return filaEncontrada?filaEncontrada:-1;
// // }












// // #define COLS

// // int sonIguales(int * fila1, int * fila2, int dim)
// // {
// //     int retVal = 1;

// //     for(int i = 0; i < dim && retVal; i++)
// //     {
// //         if(fila1[i] != fila2[i])
// //         {
// //             retVal = 0;
// //         }    
// //     }
// //     return retVal;
// // }

// // void sumaFilas(int * fila1, int * fila2, int * resp, int dim)
// // {
// //     for(int i = 0; i < dim; i++)
// //     {
// //         resp[i] = fila1[i]+fila2[i];    
// //     }
// // }

// // void esResultado(int m[][COLS], int filas, int cols, int f)
// // {
// //     int r[COLS] = {0};

// //     int match = 0;

// //     for(int i = 0; i < filas && !match; i++)
// //     {
// //         for(int j = 0; j < filas && !match; j++)
// //         {
// //             if(i != f && j != f && i != j)
// //             {
// //                 sumaFilas(m[i],m[j],r, cols);

// //                 match = sonIguales(r,m[f],cols);
// //             }           
// //         }
// //     }

// //     if(match)
// //     {
// //         for(int i = 0; i < cols; i++)
// //         {
// //             m[f][i] = 0;        
// //         }    
// //     }
// // }














// // void resta( int vec1[], int vec2[], int resp[] )
// // {

// // 	int r=0, esta;	

// // 	for (int i=0; vec1[i]!=-1; i++)
// // 	{
// // 		esta=1;
		
// // 		for (int j=0; vec2[j]!=-1 && esta; j++)
// // 		{
// // 			if (vec1[i]==vec2[j])
// // 			{
// // 				esta=0;
// // 			}
// // 		}
		
// // 		if (esta)
// // 		{
// // 			resp[r++]=vec1[i];
// // 		}
// // 	}
	
// // 	resp[r]=-1;
// // }


// // int main(void){
// //     int vec1[] = {1, 9, 2, 6, 3, 5, -1};
// //     int vec2[] = {3, 2, 8, 2, -1};
// //     int resta12[sizeof(vec1)/sizeof(vec1[0])];

// //     resta(vec1, vec2, resta12);
// //     printf("v1 - v2 = ");
// //     for(int i = 0; resta12[i] != -1; i++)
// //         printf("%d, ",resta12[i]);
// //     puts("");

// //     int resta21[sizeof(vec2) / sizeof(vec2[0])];
// //     resta(vec2, vec1, resta21);
// //     printf("v2 - v1 = ");
// //     for(int i = 0; resta21[i] != -1; i++)
// //         printf("%d, ",resta21[i]);
// //     puts("");
    
// //     int resta11[1];
// //     resta(vec1,vec1,resta11);
// //     printf("v1 - v1 = ");
// //     printf("%d",resta11[0]);

// //     return 0;
// // }











// #define DIM 3

// int esAscendente(const int mat[][DIM], int fils, int cols, int v[])
// {
//     int asc = 1;                                                    // Inicializo flag en 1
    
//     int posVec = 0, anterior;

//     v[0] = mat[0][0];

//     for(int i=0; i<fils && asc; i++)
//     {
//         anterior = mat[i][0];

//         for(int j=0; j<cols && asc; j++)
//         {
//             if( anterior > mat[i][j])
//             {   
//                 asc=0;
//             }

//             if( (mat[i][j] > mat[i+1][j]) && (i < fils-1))
//             {    
//                 asc=0;
//             }

//             anterior = mat[i][j];

//             // Completo el vector
//             if( asc && (v[posVec] < mat[i][j]) )
//             { 
//                 v[++posVec] = mat[i][j];
//             }
//         }
//     }

//     return (asc ? ++posVec : 0);                                    // Me falto sumar uno dimVec = posVec + 1
// }


// // int main(void)
// // {
// //     const int m[DIM][DIM] = {
// //         {1,2,3},
// //         {2,3,4},
// //         {5,6,7},
// //     };

// //     int vec[30] = {0};
// //     int dimVec = esAscendente(m, 3, 3, vec);

// //     for(int i=0; i<dimVec; i++)
// //     {
// //         printf("%d ", vec[i]);
// //     }
// //     putchar('\n');
// // }



// // int reemplazar(char * string)
// // {

// // 	int j=0, i=1;

// // 	for (; string[i]!=0; i++)
// // 	{
// // 		if (string[i-1]=='#' && string[i]=='(')
// // 		{
// // 			string[j++]='[';
// // 			i++;
// // 		}
// // 		else if (string[i-1]=='#' && string[i]==')')
// // 		{
// // 			string[j++]=']';
// // 			i++;
// // 		}
// // 		else
// // 		{
// // 			string[j++]=string[i-1];
// // 		}
// // 	}
// // 	string[j++]=string[i-1];
// // 	string[j]=0;
// // }

// // int main(void){
        
// //     char s[] = "123 #( abc ##(  (#(  #)  #]";
// //     reemplazar(s);
// //     printf("%s",s);

// //     return 0;
// // }






char* aparece(char* s1, const char* s2)
{
	char *pos;
	
	pos = strstr(s1, s2);

	if (pos != NULL)
	{
	
	int dim = strlen(s2);
	
    int i=0;

	for (; pos[dim]; i++, dim++)
	{
		pos[i]=pos[dim];
	}
    
    pos[i]=0;

    return pos;
    }
    return NULL;
}

int main(){

	char *s1 = "texto en el que se busca";
	char s2[] = {"en"};

char *var = aparece(s1, s2);

printf("%s", s1);

if(var == NULL)
    printf("toti gay\n");
    
return 0;
}