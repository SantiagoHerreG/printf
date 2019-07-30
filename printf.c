#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _write_char - function that prints a char
 * @c: character to be printed
 * @buffer: string allocated in the heap, where chars are kept until printing
 * Return: write function
 */
int _write_char(char c, char *buffer)
{
	buffer[0] = c;
	return (1);
}
/**
 * _print_string - function that prints a string using callback
 * @count: number of chars to be printed
 * @buffer: string allocated in the heap, where chars are kept until printing
 * Return: void
 */
void _print_string(char *buffer, int count)
{
		write(1, buffer, count);
}
/**
 * _special_chars - checks and prints special and naturals characters
 * @str: pointer to the string in the next char to be printed
 * @buffer: string allocated in the heap, where chars are kept until printing
 * Return: 1 (char printed
 */
int _special_chars(char *str, char *buffer)
{
	int k = 1, i = 0;

	if (str[k] == 'n')
		buffer[i] = '\n';
	else if (str[k] == '"')
		buffer[i] = '"';
	else if (str[k] == '\'')
		buffer[i] = '\'';
	else if (str[k] == '%')
		buffer[i] = '%';
	else if (str[k] == 'a')
		buffer[i] = '\a';
	else if (str[k] == 'b')
		buffer[i] = '\b';
	else if (str[k] == 'f')
		buffer[i] = '\f';
	else if (str[k] == 'r')
		buffer[i] = '\r';
	else if (str[k] == 't')
		buffer[i] = '\t';
	else if (str[k] == 'v')
		buffer[i] = '\v';
	else if (str[k] == '\\')
		buffer[i] = '\\';

	return (1);
}
/**
 * _print_selector - function that selects format
 * @str: string to be printed
 * @list: argument list
 * @buffer: string allocated in the heap, where chars are kept until printing
 * Return: number of chars printed
 */
int _print_selector(char *str, va_list list, char *buffer)
{
	int count = 0, k = 0, a = 0;

	for ( ; str[k] != 0; k++)
	{
		if (str[k] == '\\')
			count += _special_chars(str + k, buffer + count);
		else if (str[k] == '%' && str[k + 1] == 's')
			count += _print_str(va_arg(list, char *), buffer + count);
		else if (str[k] == '%' && str[k + 1] == 'c')
			count += _write_char(va_arg(list, int), buffer + count);
		else if (str[k] == '%' && (str[k + 1] == 'd' || str[k + 1] == 'i'))
			count += _print_number(va_arg(list, int), 0, buffer + count);
		else if (str[k] == '%' && str[k + 1] == 'b')
			count += _print_binary(va_arg(list, unsigned int), 0, buffer + count);
		else if (str[k] == '%' && str[k + 1] == '%')
			count += _print_percentage(str + k, buffer + count);
		else if (str[k] == '%' && str[k + 1] == 'o')
			count += _print_octal(va_arg(list, unsigned int), 0, buffer + count);
		else if (str[k] == '%' && (str[k + 1] == 'x' || str[k + 1] == 'X'))
			count += _print_hex(str[k + 1], va_arg(list, unsigned int), buffer + count);
		else if (str[k] == '%' && str[k + 1] == '\0')
		{
			a = -1;
			break;
		}
		else if (str[k] == '%' && str[k + 1] == 'u')
			count += _print_unsigned_int(va_arg(list, unsigned int), count, buffer);
		else
		{
			count += _write_char(str[k], buffer + count);
			k--;
		}
		k++;
	}
	buffer[count] = str[k];
	_print_string(buffer, count);
	if (a == -1)
		return (a);
	return (count);
}

/**
 * _printf - main function that replicates the original printf
 * @format: string to be printed containing format directives
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, k = 0, count = 0;
	char *str, *buffer;
	va_list ap;

	if (!format)
		return (-1);

	va_start(ap, format);

	for (i = 0; format[i] != 0; i++)
		;
	i++;

	str = malloc(i);
	if (str == 0)
		return (-1);

	for (k = 0; format[k] != 0; k++)
		str[k] = format[k];
	str[k] = '\0';

	buffer = malloc(1024);

	if (buffer == 0)
		return (-1);

	count = _print_selector(str, ap, buffer);
	free(str);
	free(buffer);
	va_end(ap);

	return (count);
}
