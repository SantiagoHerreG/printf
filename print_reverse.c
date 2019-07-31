#include "holberton.h"
#include <stdlib.h>
/**
 * _print_rev - prints a string in reverse order
 * @str: pointer to a string to be printed in reverse
 * @buffer: where chars are kept before printing
 * Return: void
 */

int _print_rev(char *str, char *buffer)
{
	int n, k = 0;
	char *prev, *b = "(null)";

	int count = 0;

	if (!str)
		count = _string_to_buff(b, buffer);
	else
	{
		if (str[0] == '\0')
			return (0);
		for (n = 0; str[n] != '\0'; n++)
			;

		prev = malloc(n);
		if (!prev)
			return (0);
		while (n >= 0)
		{
			prev[k] = str[n - 1];
			n--;
			k++;
		}
		count = _string_to_buff(prev, buffer);
	}

	free(prev);
	return (count);
}
