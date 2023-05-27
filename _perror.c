#include "shell.h"

/**
 *  _perror - print error
 * @argv: array
 * @c: int
 * @cmd: array
 */

void _perror(char **argv, int c, char **cmd)
{
	char *ptr = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(ptr);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(ptr);
}

