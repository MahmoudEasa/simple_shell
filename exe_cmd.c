#include "shell.h"

/**
 * exe_cmd - excute simple shell
 * @cmd: array
 * @input: string
 * @c: int
 * @argv: array
 *
 * Return: 1 if Null -1 if wrong 0 if excuted
 */

int exe_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0
				&& _strncmp(*cmd, "/", 1) != 0)
			path_cmd(cmd);

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}

