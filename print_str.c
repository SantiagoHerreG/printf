#include "holberton.h"
#include <stdlib.h>

/**
 * _print_percentage - Print percentage if format specifier is %
 * @str: String
 *
 * Return: 1 (Count) or error -1
 */

int _print_percentage(char *str)
{
	int k = 1;

	if (str[k] == '%')
		_write_char('%');
	else if (str[k] == '\0')
		exit(-1);

	return (1);
}

/**
 * _print_str - Print string with format specifier is s
 * @str: String
 *
 * Return: Count
 */

int _print_str(char *str)
{
	int count = 0;

	if (!str)
		count = _print_string("(null)");
	else
		count = _print_string(str);

	return (count);
}
