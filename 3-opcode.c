#include "monty.h"
/**
 * push_queue - push integers to queue.
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void push_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *temp;

	temp = *stack;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		mem_error();
	node->n = line_number;
	node->next = NULL;
	node->prev = NULL;

	if (*stack == NULL)
		*stack = node;
	if (temp != NULL)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
	}
}
/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void queue(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void)line_number;
}
/**
 * stack - sets the format of the data to a stack (LIFO).
 * @stack: stack
 * @line_number: file line count
 * Return: Nothing
*/
void stack(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void)line_number;
}
