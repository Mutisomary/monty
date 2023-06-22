#include "monty.h"

/**
 * parse_line - Fucntion parses a line of instruction and executes it.
 * @line: Line to be parsed
 * @line_number: Number line in the filw
 * @stack: Douible pointer to stack.
 */
void parse_line(char *line, unsigned int line_number, stack_t **stack)
{
	instruction_t *instruction;
	char *opcode = strtok(line, " \t\n");

	if (opcode == NULL || opcode[0] == '#')
		return;

	instruction = get_instruction(opcode);

	if (instruction == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	instruction->func(stack, line_number);
}
/**
 * get_opc - gets the opcode function
 * @stack: pointer to the stack or queue
 * @arg: the command
 * @val: the value
 * @line_number: the line number
 * Return: 0 on success || 1 if not a digit || -1 on error
 */

instruction_t instructions[] = {
	{"push", opcode_push},
	{"pall", opcode_pall},
	{"pint", opcode_pint},
	{"pop", opcode_pop},
	{"swap", opcode_swap},
	{"nop", opcode_nop},
	{"sub", opcode_sub},
	{"div", opcode_div},
	{"mul", opcode_mul},
	{"mod", opcode_mod},
	{NULL, NULL}
};

/**
 * get_instruction - Retrieves the instruction corresponding to the
 * given opcode.
 * @opcode: The opcode to search for.
 *
 * Return: Pointer to the instruction_t structure if found, NULL otherwise.
 */

instruction_t *get_instruction(char *opcode)
{
	int a;

	a = 0;

	while (instructions[a].opcode != NULL)
	{
		if (strcmp(instructions[a].opcode, opcode) == 0)
			return (&instructions[a]);
		a++;
	}
	return (NULL);
}
