#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		void (*f)(stack_t **stack, unsigned int line_number, const char *arg);
} instruction_t;

/* Global variable structure */
typedef struct global_s
{
	FILE *file;
	char *line;
	char *opcode;
	char *arg;
} global_t;

extern global_t global_variable;

void push(stack_t **stack, unsigned int line_number, const char *arg);
void pall(stack_t **stack, unsigned int line_number, const char *arg);
void parse_line(unsigned int line_number);
void exe_inst(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void op_pint(stack_t **stack, unsigned int ln,
		__attribute__((unused))const char *arg);
void op_pop(stack_t **stack, unsigned int ln,
		__attribute__((unused))const char *arg);
void op_swap(stack_t **stack, unsigned int ln,
		__attribute__((unused))const char *arg);
void op_nop(stack_t **stack, unsigned int ln,
		__attribute__((unused))const char *arg);

#endif
