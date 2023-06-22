#include "monty.h"
/**
 * free_stack - Frees the entire stack.
 * @stack: Double pointer to the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		stack_t *next = current->next;

		free(current);
		current = next;
	}
}
