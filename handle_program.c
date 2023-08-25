#include "monty.h"
/**
 * end_program - end monty program on success
 * Return: Nothing
*/
void end_program(void)
{
	if (stack_h)
		free_stack(&stack_h);
	if (file)
		fclose(file);
	if (line)
		free(line);
}
/**
 * exit_program - exits program on failure
 * Return: Nothing
*/
void exit_program(void)
{
	if (stack_h)
		free_stack(&stack_h);
	if (file)
		fclose(file);
	if (line)
		free(line);
	exit(EXIT_FAILURE);
}
/**
 * free_stack - frees stack from the top
 * @stack: stack frames
 * Return: Nothing
*/
void free_stack(stack_t **stack)
{
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	free(*stack);
}
/**
 * clean_arg - cleans opcode argumnts to unsigned integers
 * @num_arg: opcode argument
 * Return: unsigned integer on success, -1 on failure
*/
int clean_arg(char *num_arg)
{
	int i = 0;
	int num;

	if (num_arg == NULL)
		return (-1);
	while (num_arg[i])
	{
		if (!(num_arg[i] >= '0' && num_arg[i] <= '9'))
			return (-1);
		i++;
	}
	num = atoi(num_arg);
	return (num);
}
