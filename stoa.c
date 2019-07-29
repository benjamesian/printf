#include "holberton.h"

/**
 * stoa - Return the next string in va_list
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: Always 0
 */
int stoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	char *string = va_arg(valist, char *);

	if (!string)
		return (1);
	string_to_buffer(string, buffer, pos, n_printed);

	return (0);
}
