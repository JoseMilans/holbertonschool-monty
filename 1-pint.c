#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack
 *@stack: pointer to top of stack
 *@ln: line num
 *@arg: arg
 *Return: void
 */

void op_pint(stack_t **stack, unsigned int ln,
		__attribute__((unused))const char *arg)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
