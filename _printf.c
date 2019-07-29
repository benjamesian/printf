#include "holberton.h"

/**
 * get_elem - read the specifier or string starting at position i
 * @fmt: format string containing strings and specifiers
 * @_i: current position in format string
 * @valist: list with next argument
 * @buff: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 *
 * Return: 0 on success, else 1
 */
int get_elem(const char *fmt, int *_i, va_list valist, char *buff, int *pos, int *n_printed)
{
	int j, current_len, q, i;
	char *spec;
	char sp;

	i = *_i;

	if (fmt[i] == '%')
	{
		current_len = get_specifier_length(fmt + i);

		spec = malloc(sizeof(*spec) * current_len);
		if (!spec)
			return (1);
		_strncpy(spec, fmt + i + 1, current_len - 1);
		spec[current_len - 1] = '\0';

		sp = validate_spec(spec);

		if (!sp)
		{
			free(spec);
			if (fmt[i + 1])
			{
				q = 0;
				for (j = 1; fmt[i + j]; j++)
				{
					if (fmt[i + j] != ' ')
					{
						q = 1;
						break;
					}
				}

				if (q == 0)
				{/* % > spaces > \0 */
					*n_printed = -1;
					*_i += 2;
					return (0);
				}
				else if (fmt[i + 1] == ' ')
				{
					buffer_full(buff, pos, n_printed);
					buff[(*pos)++] = '%';
					buffer_full(buff, pos, n_printed);
					if (fmt[i + j] != '%')
						buff[(*pos)++] = ' ';
					*_i += j + (fmt[i + j] == '%');
					return (0);
				}
				buffer_full(buff, pos, n_printed);
				buff[(*pos)++] = '%';

				if (fmt[i + 1] == '%' && !fmt[i + 2])
				{
					buffer_full(buff, pos, n_printed);
					buff[(*pos)++] = '%';
					*n_printed = -1;
					*_i += 2;
					return (0);
				}
			}
			else
				*n_printed = -1;
			*_i += 1;
			return (0);
		}
		if (get_type(sp)(valist, buff, pos, n_printed))
		{
			free(spec);
			return (1);
		}
		free(spec);
	}
	else
	{
		current_len = get_substring_length(fmt + i);
		for (j = 0; j < current_len; j++)
		{
			buffer_full(buff, pos, n_printed);
			buff[(*pos)++] = fmt[i + j];
		}
	}
	*_i += current_len;
	return (0);
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
	int i, pos = 0, n_printed = 0, chars_to_print, get_ok;
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
		get_ok = get_elem(format, &i, valist, buffer, &pos, &n_printed);
		if (get_ok == 1)
			return (-1);
	}
	va_end(valist);

	chars_to_print = get_printable_length(buffer);
	print(buffer, chars_to_print);
	if (n_printed >= 0)
		n_printed += chars_to_print;
	return (n_printed);
}
