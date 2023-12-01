typedef int elemType;
typedef struct dictCDT * dictADT;
typedef int (*compare)(elemType, elemType);

/*
** Crea un nuevo diccionario para asociar pares de clave / valor. 
** Inicialmente está vacío.
** Se inserta una copiatanto de la clave como del valor
*/
dictADT newDict(compare cmp);

/* Libera todos los recursos reservados por el TAD */ 
void freeDict(dictADT m);

/*
** Agrega un elemento al diccionario. Si key o value son NULL, no los agrega
**  key: clave. Se inserta una COPIA de la clave recibida
**  value: valor asociado a la clave. Se inserta una COPIA del valor recibido
** Si ya existía la clave, el valor se pisa con value (se lo considera una actualización) 
*/
void addkey (dictADT d, const elemType * key, const elemType * value);

/*
** Retorna una copia del valor asociado a key o NULL si no estaba la clave
** en el diccionario 
*/
elemType * getValue (dictADT d, const elemType * key);

/*
** Vector que contenga una copia de todas las claves
** Cada elemento del vector es una COPIA de las claves en el diccionario
** El vector debe finalizar en NULL
** Si no hay claves (el diccionario está vacío) retorna un vector que sólo contiene NULL
*/
elemType ** keys (dictADT d);