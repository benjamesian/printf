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

	for (len = 0; s[len] && !(s[len] == '%' && !is_escaped); len++)
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
 * _printf - prints a formatted string
 * @format: format string
 *
 * Return: On success the number of bytes printed.
 * On error, a negative number.
 */
int _printf(const char *format, ...)
{
	int i, j = 0, n_strings = 0, in_string = 1, is_escaped = 0, format_len, total_length = 0, current_str_len, switch_index = 0;
	char next = '\0';
	char **buffer;
	va_list valist;

	if (!format)
		return (-1);

	buffer = malloc(sizeof(*buffer) * 1024);

	if (!buffer)
		return (-2);

	va_start(valist, format);
	format_len = _strlen(format);

/* get number of strings to store in buffer */
	for (i = 0; format[i] != '\0'; i++)
	{
		is_escaped = (format[i] == '\\' && !is_escaped);
		next = format[i + 1];

		if (in_string)
		{
			if (!is_escaped && format[i] == '%')
			{
				in_string = 0;
				n_strings++;
				current_str_len = i - switch_index;
				switch_index = i;
				total_length += current_str_len;
				buffer[j] = malloc();
				if (!(j % 1024))
				{/* move bffer */

				}
			}
		}
		else
		{
/*
 *			if (!is_valid_specifier_char(format[i]))
 *			{
 *				in_string = 1;
 *				n_strings++;
 *			}
 */
			in_string = 1;
			n_strings++;
			switch_index = i;
		}
	}

	va_end(valist);
}
