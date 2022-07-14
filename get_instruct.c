#include "monty.h"

/**
 * get_instruct - check op against valid instructions
 * @instruct: instruction to check
 * @stack: double pointer to the beginnig of the stack
 * @index_line: script line index
 *
 * Return: void
 */
void get_instruct(char *instruct, stack_t **stack, unsigned int index_line)
{
	size_t i;

	instruction_t check_instruct[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{NULL, NULL}
	};
	for (i = 0; check_instruct[i].opcode != NULL; i++)
	{
		if (strcmp(check_instruct[i].opcode, instruct) == 0)
		{
			check_instruct[i].f(stack, index_line);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", index_line, instruct);
	exit(EXIT_FAILURE);
}
