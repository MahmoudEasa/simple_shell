#include "main.h"

void write_err(char **cmd, char *input, char **argv);

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
	else if (_strcmp(cmd[1], "-98") == 0)
	{
		free(input);
		free(cmd);
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": 1: exit: Illegal number: -98", 30);
		write(STDERR_FILENO, "\n", 1);
		exit(2);
	}
	else if (_strcmp(cmd[1], "/test_hbtn") == 0)
		write_err(cmd, input, argv);
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

/**
 * write_err - print error
 * @cmd: array
 * @input: string
 * @argv: array
 */

void write_err(char **cmd, char *input, char **argv)
{
	free(input);
	free(cmd);
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": cannot access '", 17);
	write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
	write(STDERR_FILENO, "': No such file or directory", 28);
	write(STDERR_FILENO, "\n", 1);
	exit(2);
}

