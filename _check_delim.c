#include "main.h"

/**
 * _check_delim - a function that check delimeters
 * @c: input character that checked
 * @str: input string that checked
 *
 * Return: return 0 if false 1 if success
*/

unsigned int _check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		if (c == str[i])
			return (1);

	return (0);
}

