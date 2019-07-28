#include "holberton.h"

/**
 * get_next_elem - read the specifier or string starting at position i
 * @format: format string containing strings and specifiers
 * @i: current position in format string
 * @width: width of element just read in format string
 * @valist: elements that will replace specifiers
 *
 * Return: On success the resulting element in a newly allocated string.
 * On error, NULL is returned.
 */
void get_next_elem(const char *format, int i, int *width, va_list valist, char *buffer, int *pos, int *n_printed)
{
	int j, current_len;
	char *spec;

	if (format[i] == '%')
	{
		current_len = get_specifier_length(format + i);

		spec = malloc(sizeof(*spec) * current_len);
		if (!spec)
			exit(98);

		get_type(spec)(valist, buffer, pos, n_printed);

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
	int i = 0, cur_len, pos = 0, n_printed = 0;
	char buffer[BUFFER_SIZE];
	va_list valist;

	if (!format)
		return (-1);

	buffer[BUFFER_SIZE - 1] = '\0';

	va_start(valist, format);
	while (format[i] != '\0')
	{
		get_next_elem(format, i, &cur_len, valist, buffer, &pos, &n_printed);
		i += cur_len;
	}
	va_end(valist);

	return (n_printed);
}
