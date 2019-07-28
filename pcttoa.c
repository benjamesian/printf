#include "holberton.h"

/**
 * pcttoa - convert % to a string
 *
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: Always 0
 */
int pcttoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	(void) valist;

	buffer_full(buffer, pos, n_printed);
	buffer[*pos] = '%';
	pos++;

	return (0);
}
