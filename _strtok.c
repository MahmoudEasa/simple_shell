#include "main.h"

/**
 * _strtok - a function that seprate a string when find delimeter
 * @str: an input string
 * @delims: an input delimeters
 * Return: return string if success
*/


char *_strtok(char *str, const char *delims)
{
	static char *str_copy;
	static size_t i;
	char *string = NULL;

	if (str)
	{
		str_copy = strdup(str);
		i = 0;
	}
	if (!str_copy || !str_copy[i])
		return (NULL);
	for (; str_copy[i]; i++)
	{
		if (str_copy[i] == *delims)
		{
			str_copy[i] = '\0';
			if (!string)
				continue;
			else
			{
				i++;
				break;
			}
		}
		else if (!string)
			string = &str_copy[i];
	}
	if (!string)
		free(str_copy);
	return (string);
}
