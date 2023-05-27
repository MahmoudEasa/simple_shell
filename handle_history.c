#include "shell.h"

/**
 * handle_history - handle history
 * @input: string
 *
 * Return: -1 Fail 0 Succes
 */

int handle_history(char *input)
{
	int len = 0;
	ssize_t fd, w;
	char *filename = ".simple_shell_history";

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		w = write(fd, input, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}

