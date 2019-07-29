#include "holberton.h"
/**
 * _print_octal - prints a number converted into octal
 * @n: unsigned integer
 * @count: chars printed
 * Return: Counter for number of chars printed
 */

int _print_octal(unsigned int n, int count)
{
	if (n / 8)
		count = _print_octal(n / 8, count);
	_write_char(n % 8 + '0');
	return (1 + count);
}

/**
 * _print_binary - prints a number converted into binary
 * @n: unsigned integer
 * @count: chars printed
 * Return: Counter for number of chars printed
 */
int _print_binary(unsigned int n, int count)
{
	if (n / 2)
		count = _print_binary(n / 2, count);
	_write_char(n % 2 + '0');
	return (1 + count);
}
