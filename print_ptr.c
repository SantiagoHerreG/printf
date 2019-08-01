#include "holberton.h"
/**
 * _print_ptr - prints a long argument converted into hexadecimal
 * @p: Pointer to count buffer
 * @n: Decimal number to be converted
 * @buffer: buffer array
 * @count: Count chars
 * Return: Counter for number of chars printed
 */

int _print_ptr(int *p, unsigned long n, char *buffer, int count)
{
	unsigned int remainder;
	int i, j = 0;
	char hex_rev[2000], *ptr_0x = "0x", *ptr_null = "(nil)";

	if (!n)
		count = _string_to_buff(p, ptr_null, buffer, count);
	else
	{
		if (n == 0)
			hex_rev[j++] = 48;

		while (n != 0)
		{
			remainder = n % 16;
			if (remainder < 10)
				hex_rev[j++] = 48 + remainder;
			else
				hex_rev[j++] = 87 + remainder;
			n = n / 16;
		}

		count = _string_to_buff(p, ptr_0x, buffer, count);

		for (i = j - 1; i >= 0; i--)
			count = _write_char(p, hex_rev[i], buffer, count);
	}
	return (count);
}
