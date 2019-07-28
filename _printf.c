#include "holberton.h"

/**
 * get_next_elem - read the specifier or string starting at position i
 * @format: format string containing strings and specifiers
 * @i: current position in format string
 * @width: width of element just read in format string
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 */
void get_next_elem(const char *format, int i, int *width, va_list valist,
		   char *buffer, int *pos, int *n_printed)
{
	int j, current_len;
	char *spec;
	int (*type_to_buffer)(va_list, char *, int *, int *);

	if (format[i] == '%')
	{
		current_len = get_specifier_length(format + i);

		spec = malloc(sizeof(*spec) * current_len);
		if (!spec)
			exit(98);
		_strncpy(spec, format + i + 1, current_len - 1);
		spec[current_len - 1] = '\0';

		type_to_buffer = get_type(spec);
		type_to_buffer(valist, buffer, pos, n_printed);

		free(spec);
	}
	else
	{
		current_len = get_substring_length(format + i);

		for (j = 0; j < current_len; j++)
		{
			buffer_full(buffer, pos, n_printed);
			buffer[*pos] = format[i + j];
			(*pos)++;
		}
	}
	*width = current_len;
}

/**
 * _printf - prints a formatted string
 * @format: format string
 *
 * Return: On success the number of bytes printed.
 * On error, a negative number.
 */
int _printf(const char *format, ...)
{
	int i, cur_len, pos = 0, n_printed = 0, chars_to_print;
	char buffer[BUFFER_SIZE];
	va_list valist;

	if (!format)
		return (-1);

	for (i = 0; i < BUFFER_SIZE; i++)
		buffer[i] = '\0';
	i = 0;

	va_start(valist, format);
	while (format[i] != '\0')
	{
		get_next_elem(format, i, &cur_len, valist, buffer, &pos, &n_printed);
		i += cur_len;
	}
	va_end(valist);

/*
 *	printf("ready to print\n");
 *	printf("%s %d\n", buffer, get_printable_length(buffer));
 */
	chars_to_print = get_printable_length(buffer);
	print(buffer, chars_to_print);
	n_printed += chars_to_print;
	return (n_printed);
}
