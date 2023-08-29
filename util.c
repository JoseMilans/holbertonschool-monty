#include "monty.h"
/**
 * is_number - check if a string is a number
 * @s: string to check
 * Return: 1 if s is a number, 0 otherwise
 */
int is_number(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	if (s[0] == '-')
		i++;

	for (; s[i]; i++)
	{
		if (!isdigit(s[i]))
			return (0);
	}
	return (1);
}
/**
 * parse_line - parse a line of monty byte code
 * @line_number: the line to be parsed
 * Return: EXIT_SUCCESS on success, terminates the program with EXIT_FAILURE
 * if the opcode is push and the argument is not an integer.
 */
int parse_line(unsigned int line_number)
{
	size_t start, end;

	/* remove leading spaces */
	start = strspn(global_variable.line, " \t\n");
    /* find opcode */
	end = strcspn(global_variable.line + start, " \t\n");
	global_variable.opcode = strndup(global_variable.line + start, end);
    /* find argument */
	start += end;
	start += strspn(global_variable.line + start, " \t\n");
	end = strcspn(global_variable.line + start, " \t\n");
	if (global_variable.line[start])
		global_variable.arg = strndup(global_variable.line + start, end);
	else
		global_variable.arg = NULL;
	/* check if opcode is push and if the argument is not a number */
	if (strcmp(global_variable.opcode, "push") == 0)
	{
		if (!global_variable.arg || !is_number(global_variable.arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(global_variable.line);
			fclose(global_variable.file);
			exit(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
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
