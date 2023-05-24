#include "main.h"

/**
 * exe - execute the program
 * @arg0: string
 * @args: array of arguments
 * @env: array of environment variables
 */

void exe(char *arg0, char **args, char **env)
{
	char arg[100];

	strcpy(arg, arg0);
	free(arg0);
	if (execve(arg, args, env) == -1)
	{
		perror(args[0]);
	}
}

