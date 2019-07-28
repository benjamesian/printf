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
char *get_next_elem(const char *format, int i, int *width, va_list valist)
{
	int current_len;
	char *elem;
	char *spec;

	if (format[i] == '%')
	{
		current_len = get_specifier_length(format + i);

		spec = malloc(sizeof(*spec) * current_len);
		if (!spec)
			return (NULL);

		_strncpy(spec, format + i + 1, current_len - 1);
		elem = get_type(spec)(valist);
	}
	else
	{
		current_len = get_substring_length(format + i);
		elem = malloc(sizeof(*elem) * (current_len + 1));

		if (!elem)
			return (NULL);

		_strncpy(elem, format + i, current_len);
	}
	*width = current_len;
	return (elem);
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
	int i = 0, buff_elems = 0, total_length = 0, cur_len;
	char *elem;
	char **buffer;
	va_list valist;

	if (!format)
		return (-1);

	buffer = malloc(sizeof(*buffer) * 1024);
	if (!buffer)
		return (-2);

	va_start(valist, format);
	while (format[i] != '\0')
	{
		elem = get_next_elem(format, i, &cur_len, valist);
		if (!elem)
			return (-5);

		i += cur_len;

		buffer[buff_elems] = elem;
		buff_elems++;
	}

	for (i = 0; i < buff_elems; i++)
	{
		total_length += get_printable_length(buffer[i]);
		print(buffer[i]);
		//free(buffer[i]);
	}
	free(buffer);

	va_end(valist);
	return (total_length);
}
