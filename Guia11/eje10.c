#include <stdio.h>
#include <stdlib.h>
// #include "../Biblioteca/utillist.h"
#include <assert.h>
#include "../PI/Guia11/eje10.h"
#include <strings.h>

typedef struct node
{
    elemType head;
    struct node* tail;
    unsigned int cant;
}Tnode;

typedef Tnode* Tlist;

typedef struct bagCDT
{
    Tlist first;
    unsigned int size;
	comp cmp;
}bagCDT;

bagADT newBag(comp cmp)
{
    bagADT nuevoBag = calloc(1,sizeof(bagCDT));
    nuevoBag->cmp = cmp;

    return nuevoBag;
}


int addRec(Tlist list, elemType elem, comp cmp, int* agrego)
{   
    int c;
    if (list == NULL || (c=cmp(elem, list->head))<0)
    {
        Tlist aux = malloc(sizeof(Tnode));
        aux->head = elem;
        aux->tail = list;
        aux->cant = 1;
        *agrego = 1;
        return aux;
    }
    else if (cmp(elem, list->head)==0)
    {
        list->cant+=1;
        return list;
    }
    list->tail = addRec(list->tail, elem, cmp, agrego);
    return list;
}
unsigned int add(bagADT bag, elemType elem)
{
    int agrego=0;
    bag->first = addRec(bag->first, elem, bag->cmp, &agrego);
    if (agrego)
    {
        bag->size+=agrego;
    }
    return agrego;
}



unsigned int count(const bagADT bag, elemType elem)
{
    Tlist aux = bag->first;
    int auxsize = bag->size;

    while (auxsize > 0 && bag->cmp(elem, aux->head)!=0)
    {
        aux = aux->tail;
    }
    if (auxsize != 0)
        return aux->cant;
    return auxsize;
}


unsigned int size(const bagADT bag)
{
    return bag->size;
}


elemType mostPopular(bagADT bag)
{
    if (bag == NULL || bag->first == NULL)
    {
        exit(1);
    }
    Tlist aux = bag->first;
    int auxsize = bag->size;
    int mayor = bag->first->cant;
    elemType elem = bag->first->head;

    while (auxsize > 0)
    {
        if (aux->cant > mayor)
        {
            mayor = aux->cant;
            elem = aux->head;
        }
        aux = aux->tail;
    }
    return elem;
}
void
freeBag( bagADT bag) {
	Tlist curr = bag->first, aux;

	while (curr != NULL) {
		aux = curr->tail;
		free(curr);
		curr = aux;
	}
	free(bag);
}

int main(void) {
	bagADT bag = newBag(strcasecmp);
	assert( add(bag, "agustina") == 1 );
	assert( add(bag, "Agustina") == 2 );
	assert( add(bag, "belen") == 1 );
	assert( add(bag, "carla") == 1 );
	assert( add(bag, "CARLA") == 2 );
	assert( add(bag, "carla") == 3 );
	assert( add(bag, "daniel") == 1 );
	assert( add(bag, "emilio") == 1 );

	assert( count(bag, "carla") == 3 );
	assert( count(bag, "agustina") == 2 );
	assert( count(bag, "amelia") == 0 );
	assert( count(bag, "emilio") == 1 );
	assert( count(bag, "daniel") == 1 );
	assert( count(bag, "belen") == 1 );
	assert( size(bag) == 5 );
	assert( strcasecmp(mostPopular(bag), "carla") == 0 );

    for(int i=2; i <= 10001; i++)
        assert( add(bag, "belen") == i );
    assert(count(bag, "carla") == 3);
    assert(count(bag, "belen") ==10001);
    assert( strcasecmp(mostPopular(bag), "belen") == 0 );

    freeBag( bag );
    puts("OK!");

    bag = newBag(strcasecmp);
    puts("Al buscar el más popular de un bag vacío debe abortar");
    mostPopular(bag);
    puts("Si ud. ve esto, entonces no abortó como debería haber hecho");
    return 0;
}