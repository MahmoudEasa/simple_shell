#include "main.h"

/**
 * _strtok - a function that parse string to tokens
 * @string: string input
 * @delim: delimeter input
 *
 * Return: return pointer if success , NULL if false
 */
char *_strtok(char *string, const char *delim)
{
	static char *t_s, *n_t;
	unsigned int i;

	if (string != NULL)
		n_t = string;
	t_s = n_t;
	if (t_s == NULL)
		return (NULL);
	while (t_s[i])
	{
		if (_check_delim(t_s[i], delim) == 0)
			break;
		i++;
	}
	if (n_t[i] == '\0' || n_t[i] == '#')
	{
		n_t = NULL;
		return (NULL);
	}
	t_s = n_t + i;
	n_t = t_s;
	while (n_t[i])
	{
		if (_check_delim(n_t[i], delim) == 1)
		break;
		i++;
	}
	if (n_t[i] == '\0')
		n_t = NULL;
	else
	{
		n_t[i] = '\0';
		n_t = n_t + i + 1;
		if (*n_t == '\0')
			n_t = NULL;
	}
	return (t_s);
}
