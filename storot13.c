#include "holberton.h"

/**
 * rot13 - encode a string in rot13
 * @s: A string
 *
 * Return: Pointer to the beginning of s
 */
char *storot13(va_list valist)
{
	char w, c;
	char *s, *dest;
	int l, u, i;

	s = va_arg(valist, char *);
	dest = malloc(sizeof(*dest) * (_strlen(s) + 1));
	if (!dest)
		return (NULL);

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

	return (dest);
}
