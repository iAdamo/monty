#include "monty.h"
global_vars glob_vars;
/**
 * main - Main Entry to Monty construct
 * @ac: args count
 * @av: agrs vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	FILE *file;

	/* If the user does not give any file or more than one argument */
	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* If, for any reason, it’s not possible to open the file */
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	check_opcode(file);
	return (0);
}


/**
 * check_opcode - Checks if file contains valid instructions and processes them.
 * @file: Pointer to the input file.
 */
void check_opcode(FILE *file)
{
	char *line = NULL;
	size_t line_len = 0;
	char *token;
	char *opcode[] = {"push", "pall", NULL};
	size_t read_count = 1;
	size_t i;
	int flag;

	while (fgets(line, line_len, file) != NULL)
	{
		token = strtok(line, " \n");
		if (token == NULL)
		{
			read_count++;
			continue;
		}

		i = 0;
		flag = 0;

		while (opcode[i])
		{
			if (strcmp(opcode[i], token) == 0)
			{
				flag = 1;
				break;
			}
			i++;
		}

		if (flag == 0)
			print_error(read_count, token, file, line);

		run_bytecode(token, strtok(NULL, " \n"), read_count, file, line);
		read_count++;
	}

	fclose(file);
	if (line)
		free(line);
}

/**
 * run_bytecode - runs the bytecodes line by line
 * @line: each line of the file
 * @token: num argument
 * Return: Nothing
 */
void run_bytecode(char *op, char *token, size_t rd, FILE *f, char *l)
{
	instruction_t op_var[] = {
		{"push", push},
		{"pall", pall},
	};

	stack_t *head;
	void (*func)(stack_t **stack, unsigned int line_number);
	int code;
	int i;

	if ((strcmp(op, "pall") != 0) && (code = num_atoi(token)) == -1 )
	{
		fprintf(stderr, "L%ld: usage: push integer\n", rd);
		fclose(f);
		if (l)
			free(l);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while ((op_var[i].opcode) && (strcmp(op_var[i].opcode, op) != 0))
		i++;
	func = op_var[i].f;

	func(&head, code);	
}


/**
 * print_error - print out error message to stderr
 * @d: error line number
 * @str: the particular figure causing the error
 * @file: file stream for memory close
 * @line: buffer to free
 * Return: Nothing
 */
void print_error(size_t d, char *str, FILE *file, char *line)
{
	fprintf(stderr, "L%ld: unknown instruction %s\n", d, str);
	fclose(file);
	if (line)
		free(line);
	exit(EXIT_FAILURE);
}
