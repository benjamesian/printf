/**
 * get_type - Determine data type and function to convert to string
 * @s: The string
 *
 * Return: Pointer to function to convert to string
 */
char *(*get_type(char *s))(unsigned int, ...)
{
	spec_t specs[] = {
		{"c", ctoa},
		{"d", ntoa},
		{"i", ntoa},
		{"s", stoa},
		{"%", pcttoa},
		{NULL, NULL}
	};
	int i = 0;

	while (specs[i].s)
	{
		if (specs[i].s[0] == s[0] && s[1] == '\0')
			return (specs[i].f);
	}

	return (NULL);
}
