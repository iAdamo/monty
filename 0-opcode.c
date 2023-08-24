#include "monty.h"

void freeStack(**stack)
{
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	free(*stack);
}
void memError(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit_program();
}
void exit_program(void)
{
	fclose(file);
	if (line)
		free(line);
	exit(EXIT_FAILURE);
}

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		memError();
	node->n = line_number;

	if (*stack == NULL)
		*stack = node;
	else
	{
		node->next = *stack;
		(*stack)->prev = node;
		*stack = node;
	}
}

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;
	while (*temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
