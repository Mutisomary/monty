#include "monty.h"
/**
 * opcode_swap - Swaps two elementd on the top of the stack top.
 * @stack: Double pointer to stack
 * @line_number: Instruction line number.
 * Return: 0, 1.
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * opcode_add - Sums two elemnts at the top of the stack
 * @stack: Double pointer to stack
 * @line_number: Instruction line number.
 * Return: 0, 1.
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n + (*stack)->n);
	opcode_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * opcode_nop - Function doesn't do anything.
 * @stack: Dpouvle pointer to the stack.
 * @line_number: Instruction line number.
 * Return: 0,1.
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

