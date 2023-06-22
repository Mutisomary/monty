#define _GNU_SOURCE
#include "monty.h"
#define MAX_LINE_SIZE 1024

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector.
 * Return: EXIT_SUCCESS upon successful execution, EXIT_FAILURE otherwise.
 */
int main(int argc, char **argv)
{
	char *file_name = argv[1];
	FILE *file = fopen(file_name, "r");
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_size = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &line_size, file) != -1)
	{
		line_number++;
		parse_line(line, line_number, &stack);
	}
	free(line);
	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
