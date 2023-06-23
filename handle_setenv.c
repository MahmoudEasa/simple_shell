#include "shell.h"

/**
 * handle_setenv - handle setenv command
 * @argv: array of arguments
 * @args: array of line command
 * @status: integer
 */

void handle_setenv(char **argv, char **args, int *status)
{
	(void)argv;
	(void)status;

	setenv(args[1], args[2], 1);
}

