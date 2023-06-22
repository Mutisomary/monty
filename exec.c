#include "monty.h"
/**
 * exec_instruction - Executes instruction based on the given opcode.
 * @opcode: opcode to be executed.
 * @stack: Douvle pointer to stack.
 * @line_number: Parameter.
 * Return: 0, 1
 */
void exec_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t *instruction = get_instruction(opcode);

	if (instruction != NULL)
	{
		instruction->func(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
