#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _write_char - function that prints a char
 * @c: character to be printed
 * @p: pointer to how many times buffer is filled
 * @count: actual position in buffer
 * @buffer: string allocated in the heap, where chars are kept until printing
 * Return: write function
 */
int _write_char(int *p, char c, char *buffer, int count)
{

	if (count == 1024)
	{
	_print_string(buffer, 1024);
	count = 0;
	buffer[count] = c;
	*p += 1;
	count++;
	return (count);
	}
	buffer[count] = c;
	count++;
	return (count);
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
 * @p: pointer to how many times buffer is filled
 * @count: actual position in buffer
 * @str: pointer to the string in the next char to be printed
 * @buffer: string allocated in the heap, where chars are kept until printing
 * Return: 1 (char printed
 */
int _special_chars(int *p, char *str, char *buffer, int count)
{
	int k = 1;

	if (str[k] == 'n')
		count = _write_char(p, '\n', buffer, count);
	else if (str[k] == '"')
		count = _write_char(p, '"', buffer, count);
	else if (str[k] == '\'')
		count = _write_char(p, '\'', buffer, count);
	else if (str[k] == '%')
		count = _write_char(p, '%', buffer, count);
	else if (str[k] == 'a')
		count = _write_char(p, 'a', buffer, count);
	else if (str[k] == 'b')
		count = _write_char(p, '\b', buffer, count);
	else if (str[k] == 'f')
		count = _write_char(p, '\f', buffer, count);
	else if (str[k] == 'r')
		count = _write_char(p, '\r', buffer, count);
	else if (str[k] == 't')
		count = _write_char(p, '\t', buffer, count);
	else if (str[k] == 'v')
		count = _write_char(p, '\v', buffer, count);
	else if (str[k] == '\\')
		count = _write_char(p, '\\', buffer, count);

	return (count);
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
	int count = 0, k = 0, a = 0, *p = &a, *ptrk = &k;

	for (; str[k] != 0; k++)
	{
		if (str[k] == '\\')
			count = _special_chars(p, str + k, buffer, count);
		else if (str[k] == '%' && str[k + 1] == 's')
			count = _print_str(p, va_arg(list, char *), buffer, count);
		else if (str[k] == '%' && str[k + 1] == 'c')
			count = _write_char(p, va_arg(list, int), buffer, count);
		else if (str[k] == '%' && (str[k + 1] == 'd' || str[k + 1] == 'i'))
			count = _print_number(p, va_arg(list, int), count, buffer);
		else if (str[k] == '%' && str[k + 1] == 'b')
			count = _print_binary(p, va_arg(list, unsigned int), count, buffer);
		else if (str[k] == '%' && str[k + 1] == '%')
			count = _print_percentage(p, str + k, buffer, count);
		else if (str[k] == '%' && str[k + 1] == 'o')
			count = _print_octal(p, va_arg(list, unsigned int), count, buffer);
		else if (str[k] == '%' && (str[k + 1] == 'x' || str[k + 1] == 'X'))
			count = _print_h(p, str[k + 1], va_arg(list, unsigned int), buffer, count);
		else if (str[k] == '%' && str[k + 1] == '\0')
			break;
		else if (str[k] == '%' && str[k + 1] == 'u')
			count = _print_unsigned_int(p, va_arg(list, unsigned int), count, buffer);
		else if (str[k] == '%' && str[k + 1] == 'r')
			count = _print_rev(p, va_arg(list, char *), buffer, count);
		else if (str[k] == '%' && str[k + 1] == 'R')
			count = _print_rot13(p, va_arg(list, char *), buffer, count);
		else if (str[k] == '%' && str[k + 1] == 'p')
			count = _print_ptr(p, va_arg(list, unsigned long), buffer, count);
		else
			count = _flag_sel(p, str, list, buffer, count, ptrk);
		k++;
	}
	_print_string(buffer, count);
	return (str[k] == '%' ? -1 : 1024 * (*p) + count);
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
