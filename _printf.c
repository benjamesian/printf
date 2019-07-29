#include "holberton.h"

/**
 * contains - check if a string contains a character
 * @s: string
 * @c: character
 *
 * Return: 1 if character found in string, else 0
 */
int contains(char *s, char c)
{
	int i;

	if (!s)
		return (0);

	for (i = 0; s[i]; i++)
		if (s[i] == c)
			return (1);

	return (s[i] == c);
}

/**
 * validate_spec - check if a specifier is valid for printf
 * @spec: specifier
 *
 * Return: 1 if specifier is valid, else 0
 */
int validate_spec(char *spec)
{
	int i = 0;
	char *specifiers = "cs%dibuoxXSprR";

	if (!spec || !spec[0])
		return (0);
/*
 *	while (spec[i] && contains(flags, spec[i]))
 *		i++;
 */
	return (spec[i] && contains(specifiers, spec[i]));
}

/**
 * get_next_elem - read the specifier or string starting at position i
 * @format: format string containing strings and specifiers
 * @i: current position in format string
 * @width: width of element just read in format string
 * @valist: list with next argument
 * @buff: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 */
void get_next_elem(const char *format, int i, int *width, va_list valist,
		   char *buff, int *pos, int *n_printed)
{
	int j, current_len, conversion_fail;
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

		if (!validate_spec(spec))
		{
			free(spec);
			exit(99);
		}

		type_to_buffer = get_type(spec);
		conversion_fail = type_to_buffer(valist, buff, pos, n_printed);
		if (conversion_fail)
		{
			free(spec);
			exit(100);
		}
		free(spec);
	}
	else
	{
		current_len = get_substring_length(format + i);
		for (j = 0; j < current_len; j++)
		{
			buffer_full(buff, pos, n_printed);
			buff[*pos] = format[i + j];
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
