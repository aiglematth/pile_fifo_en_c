/*
Notre fichier qui contient les implémentations de fifo.h
*/

//Les includes
#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

//Les fonctions
Stack_element init_stack(int first_value)
{
	//On décide que par défaut l'adresse de l'int précédent à l'entrée de la pile est NULL
	Stack_element first_element = {first_value, NULL};
	return first_element;
}

void add_element_without_verif(Stack_element *pile, int *size_of_stack, int value)
{
	//Variables
	Stack_element add;
	//On init le prochain element de la stack
	add.value = value;
	add.last_value_pointer = NULL;
	//On va réallouer la mémoire mais on commence par incrémenter la taille de la stack
	*size_of_stack += 1;
	pile = realloc(pile, *size_of_stack * sizeof(Stack_element));
	//Verification que la realloc est réussie
	if(pile == NULL)
		exit(0);
	//On ajoute l'element
	pile[*size_of_stack - 1] = add;
        //On change l'adresse de l'element devant
        pile[*size_of_stack - 2].last_value_pointer = pile + *size_of_stack - 1;
}

void show_stack(Stack_element *pile, int *size_of_stack)
{
	for(int i = 0; i < *size_of_stack; i+=1)
		printf("Value :> [%d] Adress_to_this :> [%p] Last_value_pointer :> [%p]\n", pile[i].value, pile + i, pile[i].last_value_pointer);
}

Stack_element push_element(Stack_element *pile, int *size_of_stack)
{
        //Variables
        Stack_element *copy_stack = NULL;
	Stack_element retour = pile[0];
	//Je réalloue les valeurs
	copy_stack = malloc(sizeof(Stack_element) * *size_of_stack);
	if(copy_stack == NULL)
		exit(0);
	for(int i=0; i < *size_of_stack; i+=1)
		copy_stack[i] = pile[i];
	//Je decremente la taille de la pile
	*size_of_stack -= 1;
	//On change la pile
	pile = realloc(pile, *size_of_stack * sizeof(Stack_element));
	if(pile == NULL)
		exit(0);
	//J'affecte les nouvelles valeurs
	for(int i = *size_of_stack-1; i >= 0; i -= 1)
	{
		pile[i] = copy_stack[i+1];
		if(pile[i].last_value_pointer != NULL)
			pile[i].last_value_pointer = pile + i + 1;
	}
	//Je libère la new_stack
	free(copy_stack);
	//On retourne
	return retour;
}

Stack_element null_element(void)
{
	Stack_element e = {404, NULL};
	return e;
}

Stack_element add_element(Stack_element *pile, int *size_of_stack, int value, int max_size)
{
	Stack_element e;
	if(*size_of_stack + 1 > max_size)
		e = push_element(pile, size_of_stack);
	else
		e = null_element();
	//On ajoute l'element
	add_element_without_verif(pile, size_of_stack, value);
	//On vérifie la taille et on agit en consequent
	return e;
}
