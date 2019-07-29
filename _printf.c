#include "holberton.h"

/**
 * get_sp - get specifier
 * @fmt: format string
 * @i: current position in fmt
 * @current_len: length of specifier
 *
 * Return: specifier
 */
char get_sp(const char *fmt, int i, int *current_len)
{
	char *spec;
	char sp;

	*current_len = get_specifier_length(fmt + i);
	spec = malloc(sizeof(*spec) * (*current_len));
	if (!spec)
		return (-1);
	_strncpy(spec, fmt + i + 1, *current_len - 1);
	spec[*current_len - 1] = '\0';
	sp = validate_spec(spec);
	free(spec);
	return (sp);
}

void get_sub(const char *fmt, int i, int *current_len,
	     char *buf, int *pos, int *n_p)
{
	int j;

	*current_len = get_substring_length(fmt + i);
	for (j = 0; j < *current_len; j++)
	{
		buffer_full(buf, pos, n_p);
		buf[(*pos)++] = fmt[i + j];
	}
}

/**
 * get_el - read the specifier or string starting at position i
 * @fmt: format string containing strings and specifiers
 * @_i: current position in format string
 * @vl: list with next argument
 * @buf: character buffer for printing
 * @pos: position in the buffer
 * @n_p: number of printable characters
 *
 * Return: 0 on success, else 1
 */
int get_el(const char *fmt, int *_i, va_list vl, char *buf, int *pos, int *n_p)
{
	int j = 1, current_len, i = *_i;
	char sp;

	if (fmt[i] == '%')
	{
		sp = get_sp(fmt, i, &current_len);
		if (sp == -1)
			return (1);
		if (!sp)
		{
			if (fmt[i + 1])
			{
				while (fmt[i + j] == ' ')
					j++;
				if (!fmt[i + j])
				{/* % > spaces > \0 */
					*n_p = -1;
					*_i += j;
					return (0);
				}
				else if (fmt[i + 1] == ' ')
				{
					string_to_buffer("%", buf, pos, n_p);
					if (fmt[i + j] != '%')
						string_to_buffer(" ", buf,
								 pos, n_p);
					*_i += j + (fmt[i + j] == '%');
					return (0);
				}
				string_to_buffer("%", buf, pos, n_p);
			}
			else /* "%" */
				*n_p = -1;
			current_len = 1; }
		else if (get_type(sp)(vl, buf, pos, n_p))
			return (1); }
	else
		get_sub(fmt, i, &current_len, buf, pos, n_p);
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
		get_ok = get_el(format, &i, valist, buffer, &pos, &n_printed);
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
