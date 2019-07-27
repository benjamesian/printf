#include "holberton.h"

/**
 * is_valid_specifier_char - check if a character is a valid specifier char
 * @c: character to check
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_specifier_char(char c)
{
	return (c == 'd' || c == 'i' || c == 'c' || c == 's' || c == '%');
}

/**
 * get_substring_length - count characters until start of character specifier
 * @s: pointer to initial character in string
 *
 * Return: number of characters from initial character to character specifier
 */
int get_substring_length(char *s)
{
	int len, is_escaped = 0;

	for (len = 0; s[len] != '\0' && !(s[len] == '%' && !is_escaped); len++)
		is_escaped = (s[len] == '\\' && !is_escaped);

	return (len);
}

/**
 * get_specifier_length - get number of characters in a character specifier
 * @s: first character in character specifier
 *
 * Return: On success number of characters in character specifier
 * On error (invalid specifier), 0 is returned.
 */
int get_specifier_length(char *s)
{
	return (1);
}

/**
 * get_printable_length - get printable length
 * @s: string to print
 *
 * Return: printable length
 */
int get_printable_length(char *s)
{
	int i, j, is_escaped = 0;

	for (i = 0, j = 0; s[i] != '\0'; i++, j++)
	{
		is_escaped = (s[i] == '\\' && !is_escaped);
		if (is_escaped)
			j--;
	}

	return (j);
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
	int i, buffer_elements = 0, total_length = 0, current_len;
	char next = '\0';
	char **buffer;
	va_list valist;

	if (!format)
		return (-1);

	buffer = malloc(sizeof(*buffer) * 1024);

	if (!buffer)
		return (-2);

	va_start(valist, format);

/* get number of strings to store in buffer */
	for (i = 0, buffer_elements = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
			current_len = get_specifier_length(format + i);
		else
		{
			current_len = get_substring_length(format + i);
			(*get_type)(valist);
		}
		i += current_len;
		buffer_elements++;
	}

	for (i = 0; i < buffer_elements; i++)
	{
		total_length += get_printable_length(buffer[i]);
		print(buffer[i]);
	}

	print("\n");
	total_length += 1;

	va_end(valist);

	return (total_length);
}
