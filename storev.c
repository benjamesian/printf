#include "holberton.h"

/**
 * storev - get a reversed copy of a string
 * @valist: holds string to reverse
 *
 * Return: pointer to newly allocated reversed string
 */
int storev(va_list valist, char *buffer, int *pos, int *n_printed)
{
	char *_s = va_arg(valist, char *);
	char *s = _strdup(_s);

	char temp;
	int i, len;

	for (len = 0; s[len] != '\0'; len++)
		;

	for (i = len - 1; i >= len / 2; i--)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}

	return (0);
}
