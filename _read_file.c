#include "main.h"

/**
 * _read_file - a function that read command from a file
 * @name: name of file
 * @av: name of command
 *
 * Return: return -1 if false 0 if success
 */

void _read_file(char *name, char **av)
{
	FILE *fp;
	char *line = NULL, **cmd;
	size_t len = 0, count = 0, n = 0;

	fp = open(name, O_RDONLY);
	if (!fp)
		exit(EXIT_FAILURE);
	while ((getline(&line, &len, fp)) != -1)
	{
		count++;
		cmd = split_str(line);
		if (_strncmp(cmd[0], "exit", 4) == 0)
			exit_file(cmd, line, fp);
		else if (check_buil(cmd) == 0)
		{
			n = handle_buil(cmd, n);
			free(cmd);
		}
		else
		{
			n = exe_cmd(cmd, line, count, av);
			free(cmd);
		}
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

