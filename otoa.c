#include "holberton.h"

/**
 * otoa - convert an unsigned int to binary string
 * @valist: list with next argument
 *
 * Return: On success pointer to newly allocated string.
 * On error, NULL is returned.
 */
char *otoa(va_list valist)
{
	int i, j, len;
	char temp;
	unsigned int b = va_arg(valist, unsigned int);
	char *s = malloc(sizeof(char) * 12);

	if (!s)
		return (NULL);

	i = 0;
	while (b > 0)
	{
		s[i] = (b % 8) + '0';
		b /= 8;
		i++;
	}

	len = i;
	for (j = i - 1; j >= len / 2; j--)
	{
		temp = s[j];
		s[j] = s[len - j - 1];
		s[len - j - 1] = temp;
	}
	s[len] = '\0';

	return (s);
}
