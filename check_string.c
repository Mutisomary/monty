#include "monty.h"
/**
 * is_integer - checks if a string represents an integer.
 * @str: String to be checked.
 * Return: 0, 1.
 */
int is_integer(const char *str)
{
	int a = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[0] == '-' || str[0] == '+')
		a++;

	for (; str[a] != '\0'; a++)
	{
		if (str[a] < '0' || str[a] > '9')
			return (0);
	}

	return (1);
}
