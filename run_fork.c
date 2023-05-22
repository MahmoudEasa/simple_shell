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
	char arg0[30] = "/bin/";

	handle_command(command, &arg0);
	if (strcmp(arg0, "/bin/exit") == 0)
		exit_p(command);

	if (stat(arg0, &st) == 0)
	{
		pid = fork();
		if (pid == -1)
			perror("Error ");
		if (pid == 0)
		{
			if (strcmp(arg0, "/bin/echo") == 0 && command[1])
				check_echo(command, pid);
			else if (strcmp(arg0, "/bin/echo") == 0)
				free_exit(command, 1);
			exe(command, env);
		}
		else
		{
			wait(&status);
			if (command[1])
				if (strcmp(arg0, "/bin/echo") == 0
					&& strcmp(command[1], "$$") == 0)
					printf("%u\n", getppid());
		}
	}
	else
		perror(av[0]);
}

/**
 * check_echo - check echo $
 * @command: array of arguments
 * @child: PID or PPID
 */

void check_echo(char **command, pid_t child)
{
	int len, i;

	if (strcmp(command[1], "$?") == 0)
	{
		printf("%u\n", child);
		free_exit(command, 1);
	}
	else if (strcmp(command[1], "$$") == 0)
		free_exit(command, 1);
	else if (command[1][0] == '$')
	{
		len = strlen(command[1]);
		for (i = 0; i <= len; i++)
			command[1][i] = command[1][i + 1];

		printf("%s\n", getenv(command[1]));
		free_exit(command, 1);
	}
}

/**
 * handle_command - Handle The Path of command
 * @command: array of arguments
 * @arg0: array of "/bin/"
 */

void handle_command(char **command, char (*arg0)[30])
{
	if (*command[0] != '/' && (*command[0] != '.' && command[0][1] != '/'))
		strcat(*arg0, command[0]);
	else
		strcpy(*arg0, command[0]);
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

