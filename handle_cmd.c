#include "main.h"

/**
 * handle_sep - handle sep
 * @path: string
 *
 * Return: int
 */

int handle_sep(char *path)
{
	int status, i;
	pid_t pid;
	char **path_arr, **cmd_arr, **env;
	char *arg0;

	path_arr = split_str(path, ";");
	env = environ;
	for (i = 0; path_arr[i] ; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			return (-1);
		}
		if (pid == 0)
		{
			cmd_arr = split_str(path_arr[i], " ");
			arg0 = handle_command(cmd_arr);
			exe(arg0, cmd_arr, env);
		}
		else
			wait(&status);
	}
	return (0);
}
