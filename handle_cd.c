#include "shell.h"

/**
 * handle_cd - handle command cd
 * @args: array of line command
 */

void handle_cd(char **argv, char **args, int *status)
{
	(void)argv;
	(void)status;

	_chdir(args);
}

