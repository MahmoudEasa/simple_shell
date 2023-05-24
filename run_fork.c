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
<<<<<<< HEAD
	char arg0[30] = "/bin/";
	
	(void)env;
	handle_command(command, &arg0);
	if (strcmp(arg0, "/bin/exit") == 0)
=======
	char *arg0;

	arg0 = handle_command(command);
	if (strcmp(command[0], "exit") == 0)
	{
		free(arg0);
>>>>>>> 78d90883ed58f78810669b0171bff3f6b8a9d60f
		exit_p(command);
	}

	else if (strcmp(arg0, "/bin/cd") == 0)
  		_chdir(command);

	else if (stat(arg0, &st) == 0)
		{
		pid = fork();
		if (pid == -1)
			perror("Error ");
		if (pid == 0)
		{
<<<<<<< HEAD
			printf("---> %s ------ %s \n", command[0] , command[1]);
			if (strcmp(arg0, "/bin/echo") == 0 && command[1])
				check_echo(command, pid);
			else if (strcmp(arg0, "/bin/echo") == 0)
				free_exit(command, 1);
			exe(command, env);
=======
			check_echo(command, pid, arg0);
			exe(arg0, command, env);
>>>>>>> 78d90883ed58f78810669b0171bff3f6b8a9d60f
		}
		else
		{
			waitpid(pid, &status, 0);
			if (command[1])
				if (strcmp(arg0, "/usr/bin/echo") == 0
					&& strcmp(command[1], "$$") == 0)
				{
					free(arg0);
					printf("%u\n", getppid());
<<<<<<< HEAD
			}
=======
				}
>>>>>>> 78d90883ed58f78810669b0171bff3f6b8a9d60f
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
	free(arg0);
	write(STDERR_FILENO, av[0], strlen(av[0]));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, command[0], strlen(command[0]));
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

	if (strcmp(arg0, "/usr/bin/echo") == 0 && command[1])
	{
		if (strcmp(command[1], "$?") == 0)
		{
			free(arg0);
			printf("%u\n", child);
			free_exit(command, 1);
		}
		else if (strcmp(command[1], "$$") == 0)
		{
			free(arg0);
			free_exit(command, 1);
		}
		else if (command[1][0] == '$')
		{
			free(arg0);
			len = strlen(command[1]);
			for (i = 0; i <= len; i++)
				command[1][i] = command[1][i + 1];

			printf("%s\n", getenv(command[1]));
			free_exit(command, 1);
		}
	}
	else if (strcmp(arg0, "/usr/bin/echo") == 0)
	{
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
	char *path, **paths, *com;
	struct stat st;
	int i = 0;

	if (stat(command[0], &st) == 0)
	{
		return (command[0]);
	}
	else
	{
		path = getenv("PATH");
		paths = split_str(path, ":");
		while (paths[i])
		{
			com = malloc(sizeof(char) * (strlen(paths[i])
						+ strlen(command[0]) + 1));
			strcpy(com, paths[i]);
			strcat(com, "/");
			strcat(com, command[0]);
			if (stat(com, &st) == 0)
			{
				_free(paths);
				return (com);
			}
			else
				free(com);
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

