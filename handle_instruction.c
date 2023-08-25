#include "monty.h"
/**
 * handle_instruction - handles each opcode instructions and arguments
 * @file: global variable all the file content
 * Return: Nothing
*/
void handle_instruction(FILE *file)
{
	char *instruct, *num_arg;
	int i = 0, line_count = 1;
	size_t len = 0;
	void (*op_address)(stack_t **stack, unsigned int line_number);
	instruction_t op[] = {
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
			instruct_error(op, line_count, instruct);
		if ((strcmp(op[i].opcode, "pall") != 0) && (clean_arg(num_arg)) == -1)
			int_error(line_count);
		else
		{
			op_address = op[i].f;
			op_address(&stack_h, clean_arg(num_arg));
		}
		line_count++;
	}
}
