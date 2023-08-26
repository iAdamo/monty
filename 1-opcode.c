#include "monty.h"
/**
 * pop - opcode pop removes the top element of the stack.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_program();
	}
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
