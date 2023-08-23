#ifndef MONTY_H
#define MONTY_H
/*=================Library_Header============================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*===========================================================================*/

/*===================Structs data for linked list ===========================*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef struct global_vars
{
	char *buffer;
	FILE *file;
	int op_args;
} global_vars;








void free_dlistint(stack_t *head);
/*===========================================================================*/
void push_error(FILE *fd, char *line, stack_t *stack, int count);
void ins_error(FILE *fd, char *line, stack_t *stack, char *count, int item);

void  check_opcode(FILE *);
void run_bytecode(char *op, char *token, size_t rd, FILE *f, char *l);
void print_error(size_t d, char *str, FILE *file, char *line);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)));

int num_atoi(char *str);


#endif