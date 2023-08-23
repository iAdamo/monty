#include "monty.h"

/**
 * free_dlistint - frees a dlistint_t list
 *
 * @head: head of the list
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *holder, *temp;

	holder = head;
	while (holder != NULL)
	{
		temp = holder->next;
		free(holder);
		holder = temp;
	}
}
