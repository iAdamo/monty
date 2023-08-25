#include "monty.h"
/**
 * handle_instruction - handles each opcode instructions and arguments
 * @file: global variable all the file content
 * Return: Nothing
*/
void handle_instruction(FILE *file)
{
	char *instruct, *num_arg;
	int i, line_count = 1;
	size_t len = 0;
	int num;
	void (*op_address)(stack_t **stack, unsigned int line_number);
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while ((getline(&line, &len, file)) != -1)
	{
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
		i = 0;
		while ((op[i].opcode) && (strcmp(op[i].opcode, instruct)) != 0)
			i++;
		if (op[i].opcode == NULL)
			instruct_error(line_count, instruct);
		if (strcmp(op[i].opcode, "pall") != 0 && (clean_atoi(num_arg) == 0))
			int_error(line_count);
		else
		{
			op_address = op[i].f;
			num = clean_atoi(num_arg);
			op_address(&stack_h, num);
		}
		line_count++;
	}
}
