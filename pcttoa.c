#include "holberton.h"

/**
 * pcttoa - convert % to a string
 *
 * Return: On success pointer to newly allocated string.
 * On error, NULL is returned.
 */
char *pcttoa(void)
{
	char *s = malloc(sizeof(char) * 2);

	if (!s)
		return (NULL);

	s[0] = '%';
	s[1] = '\0';

	return (s);
}
