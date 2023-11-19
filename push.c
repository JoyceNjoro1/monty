#include "monty.h"

/**
 * push_node - Adds a node to the stack
 * @head: Pointer to the stack head
 * @line_number: Line number
 * Return: No return value
 */
void push_node(stack_t **head, unsigned int line_number){

	int num, i = 0, invalid = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				invalid = 1;
		}
		if (invalid == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(bus.arg);
	if (bus.flag == 0);
		add_to_stack(head, num);
	else
		add_to_queue(head, num);
}

