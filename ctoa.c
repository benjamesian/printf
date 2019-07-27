#include "holberton.h"

/**
 * ctoa - convert a character to a string
 * @c: character to convert
 *
 * Return: On success pointer to newly allocated string.
 * On error, NULL is returned.
 */
char *ctoa(va_list valist)
{
	char c = va_arg(valist, int);
	char *s = malloc(sizeof(char) * 2);

	if (!s)
		return (NULL);

	s[0] = c;
	s[1] = '\0';

	return (s);
}
