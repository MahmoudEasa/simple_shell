#include "shell.h"

/**
 * handle_setenv - handle setenv command
 * @args: array of line command
 */

void handle_setenv(char **argv, char **args, int *status)
{
	(void)argv;
	(void)status;

	printf("Hello %s\n", args[0]);
}

