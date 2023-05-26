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
	(void)env;

	if (_strcmp_(arg0, "/usr/bin/echo") == 0
		|| _strcmp_(args[0], "/bin/echo") == 0)
			_strcpy(arg, "/bin/echo");
	else
		_strcpy(arg, arg0);

	if (*args[0] != '/')
		free(arg0);
	if (execve(arg, args, environ) == -1)
		perror(args[0]);
}

