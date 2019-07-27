#include "holberton.h"

/**
 * stoa - Return the next string in va_list
 * @valist: The next string in the list
 *
 * Return: On success pointer to newly allocated string.
 * On error, NULL is returned.
 */
char *stoa(va_list valist)
{
	int i;
	char *string = va_arg(valist, char *);
	char *s = malloc(sizeof(char) * _strlen(string));

	if (!s)
		return (NULL);

	for (i = 0; string[i] != '\0'; i++)
		s[i] = string[i];
	s[1] = '\0';

	return (s);
}
