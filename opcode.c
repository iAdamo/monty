#include "monty.h"
global_vars glob_vars;
/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node, *head;

    if (stack == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
       /** free(glob_vars.buffer);**/
        fclose(glob_vars.file);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free(glob_vars.buffer);
        fclose(glob_vars.file);
        exit(EXIT_FAILURE);
    }

    head = *stack;
    new_node->prev = NULL;
    new_node->n = glob_vars.op_args;
    new_node->next = *stack;
    if (head != NULL)
        head->prev = new_node;
    *stack = new_node;
}

/**
 * pall - Prints all elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *head = *stack;
    (void)line_number;

    while (head)
    {
        printf("%d\n", head->n);
        head = head->next;
    }
}
