#include "main.h"

/**
 * print_help - print Help
 * @cmd: array
 * @er: int
 *
 * Return: 0 Succes -1 Fail
 */

int print_help(char **cmd, int er)
{
	int fd, fw;
	char c;
	int rd = 1;
	(void)er;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		return (-1);
	}
	_putchar('\n');
	return (0);
}

