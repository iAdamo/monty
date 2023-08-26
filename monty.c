#include "monty.h"
/**
 * main - Main entry to monty program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
*/
FILE *file;
char *line;
stack_t *stack_h;
int main(int ac, char **av)
{
	if (ac != 2)
		arg_error();
	file = fopen(av[1], "r");
	if (file == NULL)
		file_error(av[1]);
	handle_instruction(file);
	end_program();

	return (0);
}
