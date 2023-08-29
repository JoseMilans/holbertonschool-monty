#include "monty.h"

/**
 * parse_line - parse a line of monty byte code
 * @line_number: the line to be parsed
 */
void parse_line(unsigned int line_number)
{
	char *token;

	/* Tokenise the line and store the opcode and its argument */
	token = strtok(global_variable.line, " \n\t");
	global_variable.opcode = token ? strdup(token) : NULL;

	token = strtok(NULL, " \n\t");
	global_variable.arg = token ? strdup(token) : NULL;
/* Check if opcode is push and there's no argument or additional parameters */
	if (strcmp(global_variable.opcode, "push") == 0)
	{
		if (!global_variable.arg)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(global_variable.line);
			fclose(global_variable.file);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \n\t");
		if (token)
		{
			fprintf(stderr, "L%d: too many arguments\n", line_number);
			free(global_variable.line);
			fclose(global_variable.file);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * exe_inst - executes an instruction
 * @stack: double pointer to the head of the stack
 * @line_number: the line number
 */
void exe_inst(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};
	/* Iterate through the opcodes array and execute the matching instruction */
	while (opcodes[i].opcode)
	{
		if (strcmp(global_variable.opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number, global_variable.arg);
			free(global_variable.opcode);
			free(global_variable.arg);
			return;
		}
		i++;
	}
	/* If the opcode is not known, exit with a status of EXIT_FAILURE */
	fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, global_variable.opcode);
	free(global_variable.opcode);
	free(global_variable.arg);
	free(global_variable.line);
	fclose(global_variable.file);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - frees the memory allocated for the stack (stack_t)
 * @stack: pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	/* free each node of the stack */
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
