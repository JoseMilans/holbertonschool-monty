#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: the line number
 * @arg: the argument.
 */
void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	int n;
	stack_t *new;

	if (!arg || !is_number(arg)) /* check if arg exists and is a num */
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(global_variable.line);
		fclose(global_variable.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg); /* convert the argument to an integer */
	/* Allocate memory for the new node */
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(global_variable.line);
		fclose(global_variable.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/* Initialise new node and add it to the stack */
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * pall - prints all the values on the stack, starting from the top of th stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: the line number (void)
 * @arg: the argument (void)
 */
void pall(stack_t **stack, unsigned int line_number, const char *arg)
{
	stack_t *current;

	(void)line_number;
	(void)arg;

	/* Iter through stack and print each element's value */
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
