#include "main.h"

/**
 * split_str - split string
 * @str: string
 *
 * Return: pointer to array of string
 */

char **split_str(char *str)
{
	char **command = NULL, *arg, *strp = strdup(str);
	int len, i;

	arg = _strtok(strp, " ");
	if (arg != NULL && *arg != '#')
		len = 1;

	while (((arg = _strtok(NULL, " ")) != NULL && *arg != '#'))
		len++;
	free(strp);

	arg = _strtok(str, " ");
	if (arg && *arg != '#')
	{
		command = malloc(sizeof(char *) * (len + 1));
		if (!command)
			exit(EXIT_FAILURE);
		i = 0;
		while ((arg && *arg != '#'))
		{
			len = strlen(arg);
			command[i] = malloc(sizeof(char) * len);
				if (!command[i])
				{
					_free(command);
					exit(EXIT_FAILURE);
				}
			strcpy(command[i], arg);
			i++;
			arg = _strtok(NULL, " ");
		}
		command[i] = NULL;
	}
	return (command);
}

