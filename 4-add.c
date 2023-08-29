#include "monty.h"
/**
 * op_add - adds the top two elements of the stack
 * @stack: pointer to head of stack
 * @ln: line num
 * @arg: arg
 * Return: void
 */

void op_add(stack_t **stack, unsigned int ln,
		__attribute__((unused))const char *arg)
{

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	op_pop(stack, ln, NULL);
}
