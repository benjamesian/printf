#include "holberton.h"

/**
 * storot13 - encode a string in rot13
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: 0 on success else 1
 */
int storot13(va_list valist, char *buffer, int *pos, int *n_printed)
{
	char w, c;
	char *s, *dest;
	int l, u, i;

	s = va_arg(valist, char *);
	dest = malloc(sizeof(*dest) * (_strlen(s) + 1));
	if (!dest)
		return (1);

	c = *s;
	i = 0;
	while (c)
	{
		l = (c >= 'a' && c <= 'z');
		u = (c >= 'A' && c <= 'Z');
		w = (l * 'a') + (u * 'A');
		if (w)
			dest[i] = (((c - w) + 13) % 26) + w;
		i++;
		c = s[i];
	}

	return (0);
}
