#include "holberton.h"

/**
 * _print_percentage - Print percentage if format specifier is %
 * @str: String
 * @p: pointer to how many times buffer is full and printed
 * @count: actual position in buffer
 * @buffer: string allocated in the heap where chars are kept until printing
 * Return: 1 (Count) or error -1
 */

int _print_percentage(int *p, char *str, char *buffer, int count)
{
	int k = 1;

	if (str[k] == '%')
		count = _write_char(p, '%', buffer, count);
	return (count);
}

/**
 * _print_str - Print string with format specifier is s
 * @str: String
 * @p: pointer to how many times buffer is full and printed
 * @count: actual position in buffer
 * @buffer: string allocated in the heap where chars are kept until printing
 * Return: Count
 */

int _print_str(int *p, char *str, char *buffer, int count)
{
	char *b = "(null)";

	if (!str)
		count = _string_to_buff(p, b, buffer, count);
	else
		count = _string_to_buff(p, str, buffer, count);

	return (count);
}

/**
 * _string_to_buff - copies a string content into buffer in the heap
 * @str: string to be printed
 * @p: pointer to how many times buffer is full and printed
 * @count: actual position in buffer
 * @buffer: string allocated in the heap where chars are kept until printing
 * Return: count of chars to be printed
 */
int _string_to_buff(int *p, char *str, char *buffer, int count)
{
	int i = 0;

	while (str[i])
	{
		count = _write_char(p, str[i], buffer, count);
		i++;
	}
	return (count);
}
