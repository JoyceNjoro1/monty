#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack
 * @head: Pointer to the stack's head
 * @counter: Line number in the script
 * Return: No return value
 **/
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stackSize = 0, aux;

	current = *head;
	while (current)
	{
		current = current->next;
		stackSize++;
	}

	if (stackSize < 2)
	{
		fprintf(stderr, "L%d: Unable to add, stack size insufficient\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/* Implement addition of the top two elements here */
}

