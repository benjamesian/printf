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

/* REMOVE THIS LATER
			printf("current_len: %d\n", current_len);
*/
			spec = malloc(sizeof(*spec) * current_len);
			if (!spec)
				return (-3);

			_strncpy(spec, format + i + 1, current_len - 1);

/* REMOVE
			printf("spec: %s\n", spec);
*/
			elem = get_type(spec)(valist);

/* REMOVE
			printf("elem: %s\n", elem);
*/
		}
		else
		{
			current_len = get_substring_length(format + i);

/* REMOVE THIS LATER
			printf("current len: %d\n", current_len);
*/
			elem = malloc(sizeof(*elem) * (current_len + 1));
			if (!elem)
				return (-4);

/*			_strncpy(elem, format + i, current_len + 1); */
			_strncpy(elem, format + i, current_len);



/* REMOVE
			printf("elem: %s\n", elem);
*/
		}
		i += current_len;

		buffer[buffer_elements] = elem;
		buffer_elements++;
	}

/*	printf("buffer elements: %d\n", buffer_elements);
 */
	for (i = 0; i < buffer_elements; i++)
	{
		total_length += get_printable_length(buffer[i]);
		print(buffer[i]);
	}

	va_end(valist);

/* REMOVE THIS LATER
	printf("\n\n");
*/
	return (total_length);
}
