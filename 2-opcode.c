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
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit_program();
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_program();
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
/**
 * mod - computes the rest of the division of the second
 * top element of the stack
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit_program();
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_program();
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit_program();
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit_program();
	}
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *stacks = *stack;

	(void)line_number;

	while (stacks)
	{
		if (stacks->n >= 1 && stacks->n <= 127)
			putchar(stacks->n);
		else
			break;
		stacks = stacks->next;
		if (stacks == NULL)
			break;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	while (temp && temp->next)
	{
		swap(&temp, line_number);
		temp = temp->next;
	}
}
