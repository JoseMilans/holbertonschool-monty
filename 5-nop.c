#include "monty.h"
/**
 *op_nop - doesn’t do anything
 *@stack: pointer to head stack
 *@ln: line number
 *@arg: arg
 *Return: void
 */

void op_nop(stack_t **stack, unsigned int ln,
		__attribute__((unused))const char *arg)
{
	(void) **stack;
	(void) ln;
}
