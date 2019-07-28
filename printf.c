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
	return (write(1, &c, 1));
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
 * _print_selector - function that selects format
 * @str: string to be printed
 * @list: argument list
 * Return: number of chars printed
 */
int _print_selector(char *str, va_list list)
{
	int count = 0, k = 0;

	char *b;

	while (str[k] != 0)
	{
		if (str[k] == '\\' && str[k + 1] == 'n')
		{
			count++;
			_write_char('\n');
			k++;
		}
		else if (str[k] != '%' || (str[k + 1] != 'c' && str[k + 1] != 's'
		&& str[k + 1] == 'd' && str[k + 1] == 'i'))
		{
			_write_char(str[k]);
			count++;
		}
		else if (str[k] == '%' && str[k + 1] == 's')
		{
			b = va_arg(list, char *);
			count += _print_string(b);
			k++;
		}
		else if (str[k] == '%' && str[k + 1] == 'c')
		{
			count++;
			_write_char(va_arg(list, int));
			k++;
		}
		else if (str[k] == '%' && (str[k + 1] == 'd' || str[k + 1] == 'i'))
		{
			count += _print_number(va_arg(list, int), 0);
			k++;
		}
		k++;
	}
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
	char *str;
	va_list ap;

	va_start(ap, format);

	for (i = 0; format[i] != 0; i++)
		;
	i++;

	str = malloc(i * sizeof(char));

	for (k = 0; format[k] != 0; k++)
		str[k] = format[k];
	str[k] = '\0';

	count = _print_selector(str, ap);
	free(str);
	return (count);
}
