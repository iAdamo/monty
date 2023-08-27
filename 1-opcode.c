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
/**
 * swap - opcode swap swaps the top two elements of the stack.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *swapa;
	unsigned int temp;

	swapa = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit_program();
	}
	temp = swapa->n;
	swapa->n = swapa->next->n;
	swapa->next->n = temp;
}
/**
 * add - opcode add adds the top two elements of the stack.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit_program();
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
/**
 * nop - opcode nop doesn’t do anything.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void)line_number;
}
/**
 * sub - subtracts the top element of the stack from the second
 * top element of the stack.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit_program();
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
