#include "holberton.h"

/**
 * otoa - convert an unsigned int to binary string
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: Always 0
 */
int otoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	int i, len;
	unsigned int b = va_arg(valist, unsigned int);
	char *s = malloc(sizeof(char) * 12);

	if (!s)
		return (1);

	if (!b)
	{
		string_to_buffer("0", buffer, pos, n_printed);
		free(s);
		return (0);
	}

	for (i = 0; i < 12; i++)
		s[i] = '\0';
	i = 0;
	while (b > 0)
	{
		s[i] = (b % 8) + '0';
		b /= 8;
		i++;
	}

	len = i;
	rev_string(s);
	s[len] = '\0';

	string_to_buffer(s, buffer, pos, n_printed);
	free(s);
	return (0);
}
