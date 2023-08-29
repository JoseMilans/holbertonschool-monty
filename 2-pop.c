#include "monty.h"

/**
 *op_pop - removes the top element of the stack.
 *@stack: pointer to first stack
 *@ln:ln:  line number
 *@arg: arg
 *Return: void
 */

void op_pop(stack_t **stack, unsigned int ln,
		__attribute__((unused))const char *arg)
{
	stack_t *tmp = NULL;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);

	if (tmp)
	{
		tmp->prev = NULL;
		(*stack) = tmp;
	}
	else
	{
		(*stack) = NULL;
	}
}
