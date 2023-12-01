#include "eje2.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define CANT_LIBROS 76
#define BLOCK 10 //para copiar los versículos

typedef struct libro{
    size_t size;

    char ** versiculos;

} tLibro;

struct bibleCDT{
    tLibro libros[CANT_LIBROS];
};

bibleADT newBible(){
    bibleADT bibliaNueva = calloc(1 , sizeof(struct bibleCDT));
    return bibliaNueva;
}

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse){
    if(bookNbr > CANT_LIBROS)
        return 0;
    if(bible->libros[bookNbr - 1].size == 0){
        bible->libros[bookNbr - 1].versiculos = calloc(verseNbr + 1,sizeof(tLibro));
        bible->libros[bookNbr - 1].size = verseNbr;
    }
    else if(bible->libros[bookNbr - 1].size < verseNbr){
        bible->libros[bookNbr - 1].versiculos = realloc(bible->libros[bookNbr - 1].versiculos,(verseNbr + 1)*sizeof(tLibro));
        for(size_t i = bible->libros[bookNbr - 1].size; i <= verseNbr; i++){
            bible->libros[bookNbr - 1].versiculos[i] = NULL;
        }
        bible->libros[bookNbr - 1].size = verseNbr;
    }
    if(bible->libros[bookNbr - 1].versiculos[verseNbr - 1] == NULL){
        // lo puedo agregar, no había nada
        char* auxVerse = NULL;
        int i = 0;
        for(; verse[i] != '\0'; i++){
            if(i % BLOCK == 0){
                auxVerse = realloc(auxVerse,(i + BLOCK)*sizeof(char));
            }
            auxVerse[i] = verse[i];
        }
        auxVerse = realloc(auxVerse,(i+1)*sizeof(char));
        auxVerse[i] = '\0';
        bible->libros[bookNbr - 1].versiculos[verseNbr - 1] = auxVerse;
        return 1;
    }
    else{
        return 0;
    }
}

char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr){
    if(bookNbr = 0 || bookNbr > CANT_LIBROS|| verseNbr > bible->libros[bookNbr - 1].size || bible->libros[bookNbr - 1].versiculos[verseNbr - 1] == NULL)
        return NULL;
    char * retVerse = NULL;
    char * verseToCopy = bible->libros[bookNbr - 1].versiculos[verseNbr - 1];
    int i = 0;
    for(; verseToCopy[i] != '\0'; i++){
        if(i % BLOCK == 0){
            retVerse = realloc(retVerse,(i + BLOCK)*sizeof(char));
        }
        retVerse[i] = verseToCopy[i];
    }
    retVerse = realloc(retVerse,(i+1)*sizeof(char));
    retVerse[i] = '\0';
    return retVerse;
}

void freeBible(bibleADT bible){
    for(int i = 0; i < CANT_LIBROS; i++){
        for(int j = 0; j < bible->libros[i].size; j++){
            if(bible->libros[i].versiculos[j] != NULL){
                free(bible->libros[i].versiculos[j]);
            }
        }
        free(bible->libros[i].versiculos);
    }
    free(bible);
}


int
main(void) {
    bibleADT b = newBible();
    assert(getVerse(b, 1, 1)==NULL);
    char aux[2000];
    strcpy(aux, "En el principio creo Dios los cielos y la tierra.");
    assert(addVerse(b, 1, 1, aux)==1);
    strcpy(aux, "Y atardecio y amanecio: dia tercero.");
    assert(addVerse(b, 1, 13, aux)==1);
    assert(addVerse(b, 1, 13, "Amaos los unos a los otros")==0); // Ya estaba
    strcpy(aux, "los contados de la tribu de Dan fueron sesenta y dos mil setecientos.");
    assert(addVerse(b, 4, 39, aux)==1);
    assert(addVerse(b, 4, 46,
    "fueron todos los contados seiscientos tres mil quinientos cincuenta.")==1);
    char * v = getVerse(b, 4, 45);
    assert(v==NULL);
    v = getVerse(b, 4, 39);
    assert(strncmp(v, "los con", 7)==0);
    free(v);
    freeBible(b);

    puts("Aleluya !");
    return 0;
}