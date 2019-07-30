#include "holberton.h"
/**
 * _print_number - prints an integer as if it were a string
 * @n: integer to print
 * @count: Counter for number of characters in the integer
 * @buffer: buffer allocated in the heap
 * Return: Counter for number of characters in the integer
 */
int _print_number(int n, int count, char *buffer)
{
	unsigned int k;

	if (n < 0)
	{
		k = -n;
		_write_char(45, buffer);
		count++;
	}
	else
	{
		k = n;
	}
	if (k / 10)
	{
		count = _print_number(k / 10, count, buffer);
	}
	_write_char(k % 10 + '0', buffer + count);

	return (1 + count);
}


/**
 * _print_unsigned_int - prints an integer as if it were a string
 * @n: unsigned integer to print
 * @count: Counter for number of characters in the unsigned integer
 * @buffer: Buffer array
 *
 * Return: Counter for number of characters in the unsigned integer
 */
int _print_unsigned_int(unsigned int n, int count, char *buffer)
{
	if (n / 10)
		count = _print_unsigned_int(n / 10, count, buffer);
	buffer[count] = n % 10 + '0';
	return (1 + count);
}
