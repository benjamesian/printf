#include "holberton.h"

/**
 * btoa - convert an unsigned int to binary string
 * @valist: list with next argument
 *
 * Return: On success pointer to newly allocated string.
 * On error, NULL is returned.
 */
char *btoa(va_list valist)
{
	int i, j, len;
	char temp;
	unsigned int b = va_arg(valist, unsigned int);
	char *s = malloc(sizeof(char) * 33);

	if (!s)
		return (NULL);

	i = 0;
	while (b > 0)
	{
		s[i] = (b % 2) + '0';
		b /= 2;
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
