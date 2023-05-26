#include "main.h"

#define clear() printf("\033[H\033[J")

/**
 * main - simpli shell
 * @ac: number of arguments
 * @av: array of arguments
 * @env: array of environmen variables
 *
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	char *command = NULL, **args;
	size_t len;
	(void)ac;

	while (1)
	{
		command = malloc(sizeof(char) * 1024);
		if (!command)
			exit(EXIT_FAILURE);
		prompt(&command);
		signal(SIGINT, ctrl_c);
		if (_strcmp_(command, "clear") == 0)
		{
			free(command);
			clear();
		}
		else if (_strcmp_(command, "env") == 0)
		{
			free(command);
			print_env(env);
		}
		else if (*command == '\n')
			free(command);
		else
		{
			len = _strlen(command);
			if (command[len - 1] == '\n')
				command[len - 1] = '\0';
			args = split_str(command, " ");
			free(command);
			if (!args)
				continue;
			run_fork(args, av, env);
			_free(args);
		}
	}
	return (0);
}

/**
 * ctrl_c - A function to handle Ctr + C signal.
 * @signals: The signal to handle.
 */

void ctrl_c(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n ($) ", 6);
}
