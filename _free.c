#include "shell.h"

/**
 * _free - free array
 * @cmd: array
 * @line: char
 */

void _free(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

