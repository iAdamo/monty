#include "monty.h"
/**
 * push - opcode push pushes an element to the stack.
 * @stack: stack
 * @line_number: element
 * Return: Nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		mem_error();
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
/**
 * pall - opcode pall prints all the values on the stack, starting from
 * the top of the stack
 * @stack: stack
 * @line_number: void
 * Return: Nothing
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - opcode pint prints the value at the top of the stack.
 * @stack: stack
 * @line_number: element
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * mul - opcode mul multiplies the second top element with the top element
 * @stack: stack
 * @line_number: line number of opcode
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
/**
 * rotr - rotates the stack to the bottom.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next->next)
		last = last->next;
	while (last)
	{
		swap(&last, line_number);
		last = last->prev;
	}
}
