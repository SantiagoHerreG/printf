#include "holberton.h"

/**
 * _print_percentage - Print percentage if format specifier is %
 * @str: String
 * @buffer: string allocated in the heap where chars are kept until printing
 * Return: 1 (Count) or error -1
 */

int _print_percentage(char *str, char *buffer)
{
	int k = 1;

	if (str[k] == '%')
		_write_char('%', buffer);
	return (1);
}

/**
 * _print_str - Print string with format specifier is s
 * @str: String
 * @buffer: string allocated in the heap where chars are kept until printing
 * Return: Count
 */

int _print_str(char *str, char *buffer, int count)
{
	char *b = "(null)";

	if (!str)
		count = _string_to_buff(b, buffer, count);
	else
		count = _string_to_buff(str, buffer, count);

	return (count);
}

/**
 * _string_to_buff - copies a string content into buffer in the heap
 * @str: string to be printed
 * @buffer: string allocated in the heap where chars are kept until printing
 * Return: count of chars to be printed
 */
int _string_to_buff(char *str, char *buffer, int count)
{
	int k = 0, a = 1;

	while (str[k])
	{
		a = _write_char(str[k], buffer, count);
		if (a == 0)
			count = 0;
		count++;
		k++;
	}
	return (count);
}
