#include "main.h"

/**
 * _strncmp - a function that compare between two strings
 * @s1: first string
 * @s2: second string
 * @len: length of the second string
 *
 * Return: on success return 0
*/

int _strncmp(const char *s1, const char *s2, size_t len)
{

	int i = 0;

	while (s1[i] != '\0' && s2[i] && len != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		len--;
	}
	return (0);
}
#include "main.h"

/**
 * _strcmp -  a function that compares two strings
 * @s1: input value
 * @s2: input value
 * Return: Void
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
