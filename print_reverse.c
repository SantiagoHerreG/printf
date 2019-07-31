#include "holberton.h"
#include <stdlib.h>
/**
 * _print_rev - prints a string in reverse order
 * @str: pointer to a string to be printed in reverse
 * @p: pointer to how many times buffer was printed
 * @count: actual position in buffer
 * @buffer: where chars are kept before printing
 * Return: void
 */

int _print_rev(int *p, char *str, char *buffer, int count)
{
	int n, k = 0;
	char *prev, *b = "(null)";

	if (!str)
		count = _string_to_buff(p, b, buffer, count);
	else
	{
		if (str[0] == '\0')
			return (count);
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
		count = _string_to_buff(p, prev, buffer, count);
	free(prev);
	}
	return (count);
}
