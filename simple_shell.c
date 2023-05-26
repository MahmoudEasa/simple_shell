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
	int len, i = 0;
	ssize_t fd;
	(void)ac;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error ");
			exit(EXIT_FAILURE);
		}
	}

	while (1)
	{
		command = malloc(sizeof(char) * 1024);
		if (!command)
			exit(EXIT_FAILURE);
		if (fd)
		{
			prompt(&command, fd);
			while (command[i])
			{
				if (command[i] == '\n')
				command[i] = '\0';
				i++;
			}
		}
		else
			prompt(&command, -1);
		printf("\ncommand: %s\n", command);
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
			command[len - 1] = '\0';
			args = split_str(command, " \n\t\r\a");
			free(command);
			if (!args)
				continue;
			run_fork(args, av, env);
			_free(args);
		}
	}
	if (fd)
		close(fd);
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
