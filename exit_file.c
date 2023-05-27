#include "main.h"

/**
 * exit_file - a function that exit from file
 * @line: line from file
 * @cmd: command line
 * @fd: file descriptor
 *
 */
void exit_file(char **cmd, char *line, FILE *fd)
{
	int st, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	st = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(st);
}

