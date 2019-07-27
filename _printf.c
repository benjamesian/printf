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
	int i, n_strings = 0, in_string = 1;
	char *buffer;

/* get number of strings to store in buffer */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (in_string)
		{
			if (format[i] == '%')
			{
				in_string = 0;
				n_strings++;
			}
			continue;
		}
		else
		{
			if (!is_valid_specifier_char(format[i]))
			{
				in_string = 1;
				n_strings++;
			}
			continue;
		}
	}
}
