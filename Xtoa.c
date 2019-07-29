#include "holberton.h"

/**
 * Xtoa - convert an unsigned int to hexadecimal string (uppercase)
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: On success pointer to newly allocated string.
 * On error, NULL is returned.
 */
int Xtoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	int i, len;
	unsigned int b = va_arg(valist, unsigned int);
	char *s = malloc(sizeof(char) * 33);

	if (!s)
		return (1);

	i = 0;
	while (b > 0)
	{
		s[i] = (b % 16);
		if ((b % 16) < 10)
			s[i] += '0';
		else
			s[i] += 'A' - 10;
		b /= 16;
		i++;
	}

	len = i;
	rev_string(s);
	s[len] = '\0';

	string_to_buffer(s, buffer, pos, n_printed);
	free(s);
	return (0);
}
