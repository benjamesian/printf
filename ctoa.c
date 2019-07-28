#include "holberton.h"

/**
 * ctoa - convert a character to a string
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: Always 0
 */
int ctoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	char c = va_arg(valist, int);

	buffer_full(buffer, pos, n_printed);
	buffer[*pos] = c;
	*pos++;

	return (0);
}
