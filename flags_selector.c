#include "holberton.h"

int _flag_sel(int *p, char *str, va_list list, char *buffer, int count, int *k)
{
	int number = 0;

	if (str[*k] == '%' && (str[*k + 1] == ' ' || str[*k + 1] == '+'))
	{
		(*k)++;
		while (str[*k] == ' ')
			(*k)++;
		if (str[*k] == 'd' || str[*k] == 'i')
		{
			number = va_arg(list, int);
			if (number >= 0)
				count = _write_char(p, ' ', buffer, count);
			count = _print_number(p, number, count, buffer);
		}
		else if (str[*k] == '+' || str[*k] == '-')
		{
			for (; str[*k] == '+' || str[*k] == ' ' ||
			str[*k] == '-' || str[*k] == '#'; (*k)++)
				;
			if (str[*k] == 'd' || str[*k] == 'i')
			{
				number = va_arg(list, int);
				if (number >= 0)
					count = _write_char(p, '+', buffer, count);
				count = _print_number(p, number, count, buffer);
			}
		}
	}
	else if (str[*k] == '%' && str[*k + 1] == '#')
		count = _flag_numeral(p, str, list, buffer, count, k);
	else
		count = _write_char(p, str[*k], buffer, count);
	(*k)--;
	return (count);
}

int _flag_numeral(int *p, char *str, va_list list, char *buffer, int count, int *k)
{
	(*k)++;
	while (str[*k] == '#' || str[*k] == '+' || str[*k] == '-' || str[*k] == ' ')
		(*k)++;
	if (str[*k] == 'o')
	{
		count = _write_char(p, '0', buffer, count);
		count = _print_octal(p, va_arg(list, unsigned int), count, buffer);
	}
	else if (str[*k] == 'x')
	{
		count = _write_char(p, '0', buffer, count);
		count = _write_char(p, 'x', buffer, count);
		count = _print_h(p, 'x', va_arg(list, unsigned int), buffer, count);
	}
	else if (str[*k] == 'X')
	{
		count = _write_char(p, '0', buffer, count);
		count = _write_char(p, 'X', buffer, count);
		count = _print_h(p, 'X', va_arg(list, unsigned int), buffer, count);
	}
	else
	{
		count = _write_char(p, str[*k], buffer, count);
		(*k)++;
	}
	return (count);
}
