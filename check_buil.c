#include "shell.h"

/**
 * check_buil - check builtin functions
 * @cmd: array
 *
 * Return: 0 succes -1 fail
 */

int check_buil(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
	if (*cmd == NULL)
		return (-1);

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

