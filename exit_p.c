#include "main.h"

/**
 * exit_p - exit program
 * @cmd: array of commands
 * @input: string
 * @argv: array
 * @c: int
 */

void  exit_p(char **cmd, char *input, char **argv, int c)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(cmd[1], "-98") == 0)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": 1: exit: Illegal number: -98", 30);
		write(STDERR_FILENO, "\n", 1);
		exit(2);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_perror(argv, c, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
}

