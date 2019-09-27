#ifndef FIFO
#define FIFO

//Les structures
typedef struct stack_element
{
	int value;
	struct stack_element *last_value_pointer;
} Stack_element;

//Les fonctions
Stack_element init_stack(int first_value); //Retourne le premier element de la pile
void add_element_without_verif(Stack_element *pile, int *size_of_stack, int value); //On ajoute un element à la pile
Stack_element push_element(Stack_element *pile, int *size_of_stack);
void show_stack(Stack_element *pile, int *size_of_stack); //Show la pile
Stack_element null_element(void); //Retourne un élément de type Stack_element, mais considéré vide
Stack_element add_element(Stack_element *pile, int *size_of_stack, int value, int max_size); //On add un element avec la verif de taille

#endif
