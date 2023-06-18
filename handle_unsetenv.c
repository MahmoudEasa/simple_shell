#include "shell.h"

/**
 * handle_unsetenv - handle unsetenv command
 * @args: array of line command
 */

void handle_unsetenv(char **argv, char **args, int *status)
{
	(void)argv;
	(void)status;

	printf("Hello %s\n", args[0]);
}

