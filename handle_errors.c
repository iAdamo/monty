#include "monty.h"
/**
 * arg_error - exit program on failure for inadequate argument to the program
 * Return: Nothing
*/
void arg_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit_program();
}
/**
 * file_error - exit on failure if file is inaccessible
 * @fyle: file to the program
 * Return: Nothing
*/
void file_error(char *fyle)
{
	fprintf(stderr, "Error: Can't open file %s\n", fyle);
	exit_program();
}
/**
 * int_error - exit on failure for non integer argument or
 * no argument to opcode
 * @line_count: line number of error
 * Return: Nothing
*/
void int_error(int line_count)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_count);
	exit_program();
}
/**
 * mem_error - if malloc fails
 * Return: Nothing
*/
void mem_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit_program();
}
/**
 * instruct_error - exit on failure for file contains an invalid instruction
 * @line_count: line counts
 * @instruct: op instruct
 * Return: Nothing
*/
void instruct_error(int line_count, char *instruct)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, instruct);
	exit_program();
}
