#include "monty.h"
/**
 * handle_instruction - handles each opcode instructions and arguments
 * @file: global variable all the file content
 * Return: Nothing
 */
void handle_instruction(FILE *file)
{
	char *instruct, *num_arg;
	int line_count = 1;
	size_t len = 0;
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divs},

		{"mul", mul},

		{"mod", mod},

		{NULL, NULL}
	};

	while ((getline(&line, &len, file)) != -1)
	{
		if (line == NULL && line[0] == '#')
		{
			line_count++;
			continue;
		}
		instruct = strtok(line, " \n");
		if (instruct == NULL)
		{
			line_count++;
			continue;
		}
		while (instruct)
		{
			num_arg = strtok(NULL, " \n");
			break;
		}
		execute(op, instruct, num_arg, line_count);
		line_count++;
	}
}
/**
 * execute - executes each codes
 * @op: opcodes
 * @instruct: code instructions
 * @num_arg: number arguments
 * @line_count: file line count
 * Return: Nothing
 */
void execute(instruction_t *op, char *instruct, char *num_arg, int line_count)
{
	void (*op_address)(stack_t **stack, unsigned int line_number);
	int num, i = 0;

	while ((op[i].opcode) && (strcmp(op[i].opcode, instruct)) != 0)
		i++;
	if (op[i].opcode == NULL)
		instruct_error(line_count, instruct);
	if (strcmp(op[i].opcode, "push") == 0 && (clean_atoi(num_arg) == NULL))
		int_error(line_count);
	else if (strcmp(op[i].opcode, "push") == 0)
	{
		op_address = op[i].f;
		num = iclean_atoi(num_arg);
		op_address(&stack_h, num);
	}
	else if (strcmp(op[i].opcode, "push") != 0)
	{
		op_address = op[i].f;
		op_address(&stack_h, line_count);
	}
}
