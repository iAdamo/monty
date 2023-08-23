#include "main.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
	}
	node->n = line_number;
	node->next = NULL;
	node->prev = NULL;

	if (*stack == NULL)
	{
		*stack = node;
	}
	else
	{
		node->next = (*stack);
		(*stack)->prev = node;
		*stack = node;
	}
}

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	printf("%d\n", (*stack)->n);
}