#include "holberton.h"

/**
 * _printf - prints a formatted string
 * @format: format string
 *
 * Return: On success the number of bytes printed.
 * On error, a negative number.
 */
int _printf(const char *format, ...)
{
	int i = 0, buffer_elements = 0, total_length = 0, current_len;
	char *spec, *elem;
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
		if (format[i] == '%')
		{
			current_len = get_specifier_length(format + i);
			spec = malloc(sizeof(*spec) * current_len);
			if (!spec)
				return (-3);

			_strncpy(spec, format + i + 1, current_len - 1);
			elem = get_type(spec)(valist);
		}
		else
		{
			current_len = get_substring_length(format + i);
			elem = malloc(sizeof(*elem) * (current_len + 1));
			if (!elem)
				return (-4);
			_strncpy(elem, format + i, current_len);
		}
		i += current_len;

		buffer[buffer_elements] = elem;
		buffer_elements++;
	}

	for (i = 0; i < buffer_elements; i++)
	{
		total_length += get_printable_length(buffer[i]);
		print(buffer[i]);
	}

	va_end(valist);
	return (total_length);
}
