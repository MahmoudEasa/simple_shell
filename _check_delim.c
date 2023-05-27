#include "main.h"

/**
 * _check_delim - a function that check delimeters
 * @ch: input character that checked
 * @string: input string that checked
 *
 * Return: return 0 if false 1 if success
*/

unsigned int _check_delim(char ch, const char *string)
{
	unsigned int j;

	while (string[j])
	{
	if (ch == string[j])
		return (1);
	j++;
	}
	return (0);
}

