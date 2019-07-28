#include "holberton.h"
/**
 * _print_number - prints an integer as if it were a string
 * @n: integer to print
 * @count: Counter for number of character int he integer
 * 
 * Return: void
 */
int _print_number(int n, int count)
{
	unsigned int k;

	if (n < 0)
	{
		k = -n;
		_write_char(45);
		count++;
	}
	else
	{
		k = n;
	}
	if (k / 10)
	{
		count = _print_number(k / 10, count);
	}
	_write_char(k % 10 + '0');

	return (1 + count);
}
