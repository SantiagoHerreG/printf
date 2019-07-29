#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _write_char - function that prints a char
 * @c: character to be printed
 * Return: write function
 */
int _write_char(char c)
{
	write(1, &c, 1);
	return (1);
}


/**
 * _print_string - function that prints a string using callback
 * @s: string to be printed
 * Return: numbers of characters printed
 */
int _print_string(char *s)
{
	int i = 0;

	while (s[i] != 0)
	{
		_write_char(s[i]);
		i++;
	}

	return (i);
}
/**
 * _special_chars - checks and prints special and naturals characters
 * @str: pointer to the string in the next char to be printed
 * Return: 1 (char printed
 */
int _special_chars(char *str)
{
	int k = 1;

	if (str[k] == 'n')
		_write_char('\n');
	else if (str[k] == '"')
		_write_char('"');
	else if (str[k] == '\'')
		_write_char('\'');
	else if (str[k] == '%')
		_write_char('%');
	else if (str[k] == 'a')
		_write_char('\a');
	else if (str[k] == 'b')
		_write_char('\b');
	else if (str[k] == 'f')
		_write_char('\f');
	else if (str[k] == 'r')
		_write_char('\r');
	else if (str[k] == 't')
		_write_char('\t');
	else if (str[k] == 'v')
		_write_char('\v');
	else if (str[k] == '\\')
		_write_char('\\');

	return (1);
}
/**
 * _print_selector - function that selects format
 * @str: string to be printed
 * @list: argument list
 * Return: number of chars printed
 */
int _print_selector(char *str, va_list list, char *buffer)
{
	int count = 0, k = 0;

	for ( ; str[k] != 0; k++)
	{
		if (str[k] == '\\')
			count += _special_chars(str + k);
		else if (str[k] == '%' && str[k + 1] == 's')
			count += _print_str(va_arg(list, char *));
		else if (str[k] == '%' && str[k + 1] == 'c')
			count += _write_char(va_arg(list, int));
		else if (str[k] == '%' && (str[k + 1] == 'd' || str[k + 1] == 'i'))
			count += _print_number(va_arg(list, int), 0);
		else if (str[k] == '%' && str[k + 1] == 'b')
			count += _print_binary(va_arg(list, unsigned int), 0);
		else if (str[k] == '%' && (str[k + 1] == '%' || str[k + 1] == '\0'))
			count += _print_percentage(str + k);
		else if (str[k] == '%' && str[k + 1] == 'o')
			count += _print_octal(va_arg(list, unsigned int), 0);
		else
		{
			count += _write_char(str[k]);
			k--;
		}
		k++;
	}
	va_end(list);
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

	str = malloc(i * sizeof(char));

	for (k = 0; format[k] != 0; k++)
		str[k] = format[k];
	str[k] = '\0';

	buffer = malloc(1024);

	count = _print_selector(str, ap, buffer);
	free(str);
	va_end(ap);
	return (count);
}
