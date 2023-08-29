#include "monty.h"
/**
 *op_swap -  swaps the top two elements of the stack
 *@stack: pointer to head of stack
 *@ln: line number
 *@arg: arg
 *Return: void
 */

void op_swap(stack_t **stack, unsigned int ln,
		__attribute__((unused))const char *arg)
{
	stack_t *tmp1 = NULL, *tmp2 = NULL;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp1 = (*stack);
	tmp2 = tmp1->next;

	tmp1->next = tmp2->next;
	tmp2->prev = NULL;
	tmp2->next = tmp1;

	if (tmp1->next)
	{
		tmp1->next->prev = tmp1;
	}

	*stack = tmp2;
}
