#include "main.h"

/**
 * exe - execute the program
 * @args: array of arguments
 * @env: array of environment variables
 */

void exe(char **args, char **env)
{
	char arg0[30] = "/bin/";

	handle_command(args, &arg0);

	if (execve(arg0, args, env) == -1)
		perror(args[0]);
}

