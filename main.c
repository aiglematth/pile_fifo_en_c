/*
Le main de la pile...on l'utilise
*/

//Les includes
#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

//Le main
int main(void)
{
	//Variables
	int max_size = 4;
	Stack_element *pile = NULL;
	int size = 1;
	Stack_element e;

	//Alloc dynamique
	pile = malloc(size * sizeof(Stack_element));
	pile[0] = init_stack(0);
	//J'ajoute les elements
	add_element(pile, &size, 10, max_size);
	add_element(pile, &size, 20, max_size);
	add_element(pile, &size, 30, max_size);
        //Je show
        show_stack(pile, &size);
        printf("/* -------------------------------------------- */\n");
	e = add_element(pile, &size, 40, max_size);
        //Je show
        show_stack(pile, &size);
        printf("/* -------------------------------------------- */\n");
	//Je recup
	printf("VALUE --> %d\n", e.value);
	//Je relache la mémoire
	free(pile);
	//Fin programme
	return 0;
}
