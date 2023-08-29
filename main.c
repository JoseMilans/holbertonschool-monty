#include "monty.h"

global_t global_variable;
/**
 * main - entry point for the monty bytecode interpreter
 * @argc: the number of command line arguments
 * @argv: the command line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	size_t len = 0;

	if (argc != 2) /* check if correct num of args is given */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
    /* open the file */
	global_variable.file = fopen(argv[1], "r");
	if (!global_variable.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* read file each line and execute instruction */
	while (getline(&global_variable.line, &len, global_variable.file) != -1)
	{
		line_number++;
		parse_line(line_number);
		exe_inst(&stack, line_number);
	}
	/* clean up */
	free(global_variable.line);
	fclose(global_variable.file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
