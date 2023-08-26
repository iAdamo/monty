#include "monty.h"
/**
 * divs - divides the second top element of the stack by the
 * top element of the stack.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void divs(stack_t **stack, unsigned int line_number)
{
	stack_t *len;
	int count = 0;

	len = *stack;

	/*count of stack*/
	while (len)
	{
		count++;
		len = len->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit_program();
	}
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
