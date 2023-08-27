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
 * clean_atoi - cleans opcode argumnts to unsigned integers
 * @num_arg: opcode argument
 * Return: a string on success, NULL on failure
*/
char *clean_atoi(char *num_arg)
{
	int i = 0;
	int sign = 1;
	int num = 0;

	if (num_arg == NULL)
		return (NULL);
	while (num_arg[i])
	{
		if (num_arg[i] == '-')
			sign *= -1;
		else if (num_arg[i] >= '0' && num_arg[i] <= '9')
			num = (num * 10) + (num_arg[i] - '0');
		else
			return (NULL);
		i++;
	}
	return ("cool");
}

/**
 * iclean_atoi - cleans opcode argumnts to unsigned integers
 * @num_arg: opcode argument
 * Return: integer on success, 0 on failure
*/
int iclean_atoi(char *num_arg)
{
	int i = 0;
	int sign = 1;
	int num = 0;

	if (num_arg == NULL)
		return (0);
	while (num_arg[i])
	{
		if (num_arg[i] == '-')
			sign *= -1;
		else if (num_arg[i] >= '0' && num_arg[i] <= '9')
			num = (num * 10) + (num_arg[i] - '0');
		else
			return (0);
		i++;
	}
	return (sign * num);
}
