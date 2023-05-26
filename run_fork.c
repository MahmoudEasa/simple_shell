#include "main.h"

/**
 * run_fork - run new program
 * @command: pointer to buffer
 * @av: array of arguments
 * @env: array of environment variables
 */

void run_fork(char **command, char **av, char **env)
{
	struct stat st;
	pid_t pid;
	int status;
	char *arg0;

	arg0 = handle_command(command);
	if (_strcmp_(command[0], "exit") == 0)
	{
		if (*command[0] != '/')
			free(arg0);
		exit_p(command);
	}
	else if (_strcmp_(command[0], "cd") == 0)
		_chdir(command);
	else if (stat(arg0, &st) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			if (*command[0] != '/')
				free(arg0);
			_free(command);
			perror("Error ");
		}
		else if (pid == 0)
		{
/*			check_echo(command, pid, arg0);*/
/*			if (_strcmp_(arg0, "/usr/bin/echo") == 0
				|| _strcmp_(command[0], "/bin/echo") == 0)
					exe(, command, env);
			else*/
			exe(arg0, command, env);
		}
		else
		{
			waitpid(pid, &status, 0);
/*			if (command[1])
				if (_strcmp_(arg0, "/usr/bin/echo") == 0
					&& _strcmp_(command[1], "$$") == 0)
					printf("%u\n", getppid());*/
			if (*command[0] != '/')
				free(arg0);
		}
	}
	else
		print_error(av, command, arg0);
}

/**
 * print_error - print error
 * @av: array
 * @command: array
 * @arg0: string
 */

void print_error(char **av, char **command, char *arg0)
{
	if (*command[0] != '/')
		free(arg0);
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, command[0], _strlen(command[0]));
	write(STDERR_FILENO, ": not found\n", 13);
}

/**
 * check_echo - check echo $
 * @command: array of arguments
 * @child: PID or PPID
 * @arg0: string
 */

void check_echo(char **command, pid_t child, char *arg0)
{
	int len, i;

	if (_strcmp_(arg0, "/usr/bin/echo") == 0 && command[1])
	{
		if (_strcmp_(command[1], "$?") == 0)
		{
			free(arg0);
			printf("%u\n", child);
			free_exit(command, 1);
		}
		else if (_strcmp_(command[1], "$$") == 0)
		{
			free(arg0);
			free_exit(command, 1);
		}
		else if (command[1][0] == '$')
		{
			free(arg0);
			len = _strlen(command[1]);
			for (i = 0; i <= len; i++)
				command[1][i] = command[1][i + 1];

			printf("%s\n", _getenv(command[1]));
			free_exit(command, 1);
		}
	}
	else if (_strcmp_(arg0, "/usr/bin/echo") == 0)
	{
		write(STDIN_FILENO, "\n", 1);
		free(arg0);
		free_exit(command, 1);
	}
}

/**
 * handle_command - Handle The Path of command
 * @command: array of arguments
 *
 * Return: pointer to command
 */

char *handle_command(char **command)
{
	char *path, **paths, *cmd;
	struct stat st;
	int i = 0;

	if (stat(command[0], &st) == 0)
	{
		return (command[0]);
	}
	else
	{
		path = _getenv("PATH");
		paths = split_str(path, ":");
		while (paths[i])
		{
			cmd = malloc(sizeof(char) * (_strlen(paths[i])
						+ _strlen(command[0]) + 1));
			_strcpy(cmd, paths[i]);
			_strcat(cmd, "/");
			_strcat(cmd, command[0]);
			if (stat(cmd, &st) == 0)
			{
				_free(paths);
				return (cmd);
			}
			else
				free(cmd);
			i++;
		}

		_free(paths);
	}
	return (NULL);
}

/**
 * free_exit - free and exit program
 * @command: array of string
 * @is_arr: int 1 is array 0 is string
 */

void free_exit(char **command, int is_arr)
{
	if (is_arr)
		_free(command);
	else
		free((*command));

	exit(EXIT_SUCCESS);
}

