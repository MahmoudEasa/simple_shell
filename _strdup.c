#include "main.h"

/**
 * *_strdup - a function that returns a pointer to a newly allocated space
 * @str: input value
 * Return: return char
*/

char *_strdup(char *str)
{
	int i, j;

	char *ch;

	if (str == NULL)
	{
		return (NULL);
	}

	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}

	ch = malloc(sizeof(char) * (j + 1));

	if (ch == NULL)
	{
		return (NULL);
	}
	for (i = 0 ; str[i] ; i++)
	{
		ch[i] = str[i];
	}
	return (ch);
}
