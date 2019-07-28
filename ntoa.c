#include "holberton.h"

/**
 * _ntoa_rev - Convert a long long to a reversed string
 * @n: The long long to convert
 * @s: The reversed string
 */
void _ntoa_rev(long n, char *s)
{
	if (n == 0)
	{
		*s = '\0';
		return;
	}

	*s = (n % 10) + '0';
	_ntoa_rev(n / 10, ++s);
}

/**
 * rev_string - Reverse a string
 * @s: The string to reverse
 */
void rev_string(char *s)
{
	int i, length;
	char tmp;

	length = 0;
	for (i = 0; s[i] != '\0'; i++)
		length++;

	for (i = 0; i < length; i++)
	{
		tmp = s[i];
		s[i] = s[length - 1];
		s[length - 1] = tmp;
		length--;
	}
}

/**
 * ntoa - convert a long long to a string
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: 0 on success, 1 on allocation failure
 */
int ntoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	int digits = 0, is_negative = 0;
	long n = va_arg(valist, long);
	long copy = n;
	char *s;

	if (n < 0)
		is_negative = 1;

	if (copy == 0)
		digits = 1;
	else
	{
		while (copy)
		{
			copy /= 10;
			digits++;
		}
	}

	s = malloc(sizeof(char) * (digits + is_negative + 1));

	if (!s)
		return (1);

	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	else
	{
		_ntoa_rev(n, s);
		rev_string(s);
	}

	string_to_buffer(s, buffer, pos, n_printed);
	free(s);

	return (0);
}
