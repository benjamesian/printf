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
int get_substring_length(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0' && s[len] != '%'; len++)
		;

	return (len);
}

/**
 * get_specifier_length - get number of characters in a character specifier
 * @s: first character in character specifier
 *
 * Return: On success number of characters in character specifier
 * On error (invalid specifier), 0 is returned.
 */
int get_specifier_length(const char *s)
{
	(void) s;
	return (2);
}

/**
 * get_printable_length - get printable length
 * @s: string to print
 *
 * Return: printable length
 */
int get_printable_length(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}
