#include "monty.h"

FILE *file;
char **line;
stack_t *stack_head;


void argError(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit_program();
}
void fileError(char *fyle)
{
	fprintf(stderr, "Error: Can't open file %s\n", fyle);
	exit_program();
}
void instructError(int line_count, char *instruct)
{
	while (op[i].opcode)
	{
		if (instruct == NULL || (strcmp(op[i].opcode, instruct)) == 0)
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0)
		fprintf(stderr, "L%d: unknown instruction %s\n" line_count, instruct);
	exit_program();
}
void argError(int line_count)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_count);
	exit_program();
}
int main(int ac, char **av)
{
	if (ac != 2)
		argError();
	file = open(av[1], 'r');
	if (file == NULL)
		fileError(av[1]);
	handle_instruction(file);
	end_program();

	return (0);
}
void end_program(void)
{
	if (stack)
		freeStack(&stack);
	if (file)
		fclose(file);
	if (line)
		free(line);
}
void handle_instruction(FILE *file)
{
	size_t len = 0;
	int line_count = 0;
	instruction_t op = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while ((getline(&line, &len, file)) != -1)
	{
		instruct = strtok(line, " \n");
		while (instruct)
		{
			num_arg = strtok(NULL, " \n");
			break;
		}
		while (op[i].opcode && (strcmp(op[i].opcode, instruct)) != 0)
			i++;
		if (op[i].opcode == NULL)
			instruct_error(line_count, instruct);
		if ((clean_arg(num_arg)) == -1)
			argError(line_count);
		else
		{
			op_adress = op[i].f;
			op_adress(&stack, num_arg);
		}
		line_count++;
	}
}
