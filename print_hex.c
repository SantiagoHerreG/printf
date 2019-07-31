#include "holberton.h"
/**
 * _print_h - prints a number converted into octal
 * @option: Option for uppercase or lowercase output
 * @n: Decimal number to be converted
 * @buffer: buffer array
 * Return: Counter for number of chars printed
 */

int _print_h(char option, unsigned int n)
{
    unsigned int remainder;
    int i, j = 0;
    char hex_rev[2000];

    if (n == 0)
        hex_rev[j++] = 48;

    while (n != 0)
    {
        remainder = n % 16;
        if (remainder < 10)
            hex_rev[j++] = 48 + remainder;
        else if (remainder > 10 && option == 'X')
            hex_rev[j++] = 55 + remainder;
        else if (remainder > 10 && option == 'x')
            hex_rev[j++] = 87 + remainder;
        n = n / 16;
    }

    for (i = j - 1; i >= 0; i--)
        count = _write_char(p, hex_rev[i], buffer, count);
    return (count);
}
