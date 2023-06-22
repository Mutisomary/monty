#include "monty.h"

int is_integer(const char *str);
/**
 * opcode_push - Pushes an element to the stack.
 * @stack: Double pointer to the stack.
 * @line_number: instruction line number.
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;
	char *value_str = strtok(NULL, " \t\n");

	if (value_str == NULL || !is_integer(value_str))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(value_str);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
/**
 * opcode_pall - Prints all the elements in the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Instruction line number.
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
 * opcode_pint - Prints the top element of the stack.
 * @stack: double pointer to the stack.
 * @line_number: instruction line number.
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * opcode_pop - Removes the top element of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Instrucion line number.
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
