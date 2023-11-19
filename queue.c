#include "monty.h"

/**
 * switchToQueueMode - switches to queue mode
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void switchToQueueMode(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.isQueue = 1;
}

/**
 * enqueue - add node to the tail of the stack
 * @new_value: new value to be added
 * @head: head of the stack
 * Return: no return
 */
void enqueue(stack_t **head, int new_value)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = new_value;
	new_node->next = NULL;

	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}

	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

