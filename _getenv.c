#include "main.h"

/**
 * _getenv - a function that get a value of name in env
 * @var_name: name of string in env
 * Return: return the value if found, else return NULL
 */
char *_getenv(char *var_name)
{
	size_t len_n, len_v;
	char *value;
	int i, x, j;

	len_n = _strlen(var_name);
	while (environ[i])
	{
		if (_strncmp(var_name, environ[i], len_n) == 0)
		{
			len_v = _strlen(environ[i]) - len_n;
			value = malloc(sizeof(char) * len_v);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = len_n + 1; environ[i][x]; x++, j++)
				value[j] = environ[i][x];
			value[j] = '\0';
			return (value);
		}
		i++;
	}

return (NULL);
}
