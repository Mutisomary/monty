#include "monty.h"
int is_integer(const char *str);

/**
 * opcode_sub - Subtracts the top element of the stack
 * from the second top element.
 * @stack: Double pointer to the stack.
 * @line_number: instruction line number
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the stack.
 * @line_number: Instruction line number.
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	opcode_pop(stack, line_number);
}
/**
 * opcode_mul - Multiplies the first two top elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Instruction line number
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_mod - Returns the remainder of the division
 * of the second top element from  the top element.
 * @stack: double pointer to the stack.
 * @line_number: instruction line number.
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	opcode_pop(stack, line_number);
}
