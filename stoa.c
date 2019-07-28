#include "holberton.h"

/**
 * stoa - Return the next string in va_list
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 */
void stoa(va_list valist, char *buffer, int *pos, int *n_printed)
{
	char *string = va_arg(valist, char *);

	for (i = 0; string[i] != '\0'; i++)
	{
		buffer_full(buffer, pos, n_printed);
		buffer[*pos] = string[i];
		pos++;
	}
}
