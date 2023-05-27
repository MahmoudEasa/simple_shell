#include "main.h"

/**
 * split_str - split string
 * @input: string
 *
 * Return: array
 */

char **split_str(char *input)
{
	int i, buffsize = BUFSIZE;
	char **tokens;
	char *token;

	if (input == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * buffsize);

	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}

