#include "holberton.h"
/**
 * _print_octal - prints a number converted into octal
 * @n: unsigned integer
 * @p: pointer to number of times buffer has been printed
 * @count: chars printed
 * @buffer: string allocated in the heap where chars are kept until printing
 * Return: Counter for number of chars printed
 */

int _print_octal(int *p, unsigned int n, int count, char *buffer)
{
	if (n / 8)
		count = _print_octal(p, n / 8, count, buffer);
	count = _write_char(p, n % 8 + '0', buffer, count);
	return (count);
}

/**
 * _print_binary - prints a number converted into binary
 * @n: unsigned integer
 * @count: chars printed
 * @p: pointer to number of times buffer has been printed
 * @buffer: string allocated in the heap where chars are kept until printing
 * Return: Counter for number of chars printed
 */
int _print_binary(int *p, unsigned int n, int count, char *buffer)
{
	if (n / 2)
		count = _print_binary(p, n / 2, count, buffer);
	count = _write_char(p, n % 2 + '0', buffer, count);

	return (count);
}
