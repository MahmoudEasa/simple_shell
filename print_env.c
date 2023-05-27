#include "shell.h"

/**
 * print_env - print enviroment variable
 * @cmd: array
 * @er: int
 * Return: 0
 */

int print_env(char **cmd, int er)
{
	int len;
	size_t i;
	(void)cmd;
	(void)er;

	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

