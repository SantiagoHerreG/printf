#include "holberton.h"
#include <stdlib.h>
/**
 * _print_rot13 - encodes a string into rot13
 * @str: string to be printed into rot13
 * @p: pointer to how many times the buffer has been printed
 * @count: actual position in buffer
 * @buffer: string where chars are stored before printing
 * Return: Count
 */
int _print_rot13(int *p, char *str, char *buffer, int count)
{
	int i, a;
	char *prot, *b = "(null)";
	char abcd[52] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	char rot13[52] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};

	if (!str)
		count = _string_to_buff(p, b, buffer, count);
	else
	{
		if (str[0] == '\0')
			return (count);

		for (i = 0; str[i] != 0; i++)
			;

		prot = malloc(i);
		if (!prot)
			return (0);

		for (i = 0; str[i] != 0; i++)
		{
			for (a = 0; a <= 52; a++)
			{
				if (str[i] == abcd[a])
				{
					prot[i] = rot13[a];
					break;
				}
				if (a == 52)
					prot[i] = str[i];
			}
		}
		count = _string_to_buff(p, prot, buffer, count);
		free(prot);
	}
	return (count);
}
