#include "holberton.h"

void buffer_full(char *buffer, int *pos, int *n_printed)
{
	int chars_to_print;
	if (*pos == BUFFER_SIZE - 1)
	{
		chars_to_print = get_printable_length(buffer);
		print(buffer, chars_to_print);
		*n_printed += chars_to_print;
		*pos = 0;
	}
}
