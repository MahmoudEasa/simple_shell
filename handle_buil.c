#include "shell.h"

/**
 * handle_buil - handle builtin
 * @cmd: array
 * @er: int
 * Return: -1 fail 0 succes
 */

int handle_buil(char **cmd, int er)
{
	bul_t bil[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
		};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
			return ((bil + i)->fun(cmd, er));
		i++;
	}
	return (-1);
}

