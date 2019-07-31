#include "holberton.h"
/**
 * _print_number - prints an integer as if it were a string
 * @n: integer to print
 * @p: pointer to how many times the buffer was printed
 * @count: Counter for number of characters in the integer
 * @buffer: buffer allocated in the heap
 * Return: Counter for number of characters in the integer
 */
int _print_number(int *p, int n, int count, char *buffer)
{
	unsigned int k;

	if (n < 0)
	{
		k = -n;
		count = _write_char(p, 45, buffer, count);
	}
	else
	{
		k = n;
	}
	if (k / 10)
	{
		count = _print_number(p, k / 10, count, buffer);
	}
	count = _write_char(p, k % 10 + '0', buffer, count);

	return (count);
}

/**
 * _print_unsigned_int - prints an integer as if it were a string
 * @n: unsigned integer to print
 * @count: Counter for number of characters in the unsigned integer
 * @p: pointer to how many times buffer was filled
 * @buffer: Buffer array
 *
 * Return: Counter for number of characters in the unsigned integer
 */
int _print_unsigned_int(int *p, unsigned int n, int count, char *buffer)
{
	if (n / 10)
		count = _print_unsigned_int(p, n / 10, count, buffer);
	count = _write_char(p, n % 10 + '0', buffer, count);
	return (count);
}
