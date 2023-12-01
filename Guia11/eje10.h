
typedef struct bagCDT * bagADT;


typedef char* elemType;	// Tipo de elemento a insertar

typedef int (*comp)(elemType,elemType);
/**
** Retorna 0 si los elementos son iguales 
*/
// static int compare (elemType e1, elemType e2) {
// 	return e1 != e2;
// }


/* Retorna un nuevo bag de elementos genéricos. Al inicio está vacío */
bagADT newBag();


/* Inserta un elemento. Retorna cuántas veces está
** elem en el conjunto luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
unsigned int add(bagADT bag, elemType elem);


/* Retorna cuántas veces aparece el elemento en el bag */
unsigned int count(const bagADT bag, elemType elem);


/* Retorna la cantidad de elementos distintos que hay en el bag */
unsigned int size(const bagADT bag);


/* Retorna el elemento que aparece más veces. Si hay más de uno 
** con esa condición, retorna cualquiera de los dos. 
** Precondición: el bag no debe estar vacío. En caso de estar vacío, aborta
** la ejecución
*/
elemType mostPopular(bagADT bag);
