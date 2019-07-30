#include "holberton.h"

/**
 * _ntoa_rev - Convert a long to a reversed string
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
 * itoa - convert an integer to a string
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: 0 on success, 1 on allocation failure
 */
int itoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	int n = va_arg(valist, int);
	unsigned int unsigned_n = n;

	if (n < 0)
	{
		unsigned_n = -n;
		buffer_full(buffer, pos, n_printed);
		buffer[*pos] = '-';
		(*pos)++;
	}

	return (ntoa(unsigned_n, buffer, pos, n_printed));
}

/**
 * utoa - convert a long to a string
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: 0 on success, 1 on allocation failure
 */
int utoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	long n = va_arg(valist, long);

	return (ntoa(n, buffer, pos, n_printed));
}

/**
 * ntoa - convert a long to a string
 * @n: number to convert
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: 0 on success, 1 on allocation failure
 */
int ntoa(long n, char *buffer, int *pos, int *n_printed)
{
	int i;
	char s[12];

	for (i = 0; i < 12; i++)
		s[i] = '\0';

	if (n == 0)
	{
		s[0] = '0';
	}
	else
	{
		_ntoa_rev(n, s);
		rev_string(s);
	}

	string_to_buffer(s, buffer, pos, n_printed);

	return (0);
}
