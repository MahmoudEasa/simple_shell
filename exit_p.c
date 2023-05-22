#include "main.h"

/**
 * exit_p - exit the program
 * @command: array of arguments
 */

void exit_p(char **command)
{
	int num;

	if (command[1])
	{
		num = atoi(command[1]);
		_free(command);
		exit(num);
	}
	else
		free_exit(command, 1);
}

