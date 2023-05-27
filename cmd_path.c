#include "main.h"

/**
 * cmd_path -  a function that find full path in env
 * @cmd: command line
 * Return: return 1 if failure 0 if success
 */
int cmd_path(char **cmd)
{
	struct stat st;
	char *p, *value, *cmdpath;

	p = _getenv("PATH");
	value = _strtok(p, ":");
	while (value != NULL)
	{
		cmdpath = build_cmd(*cmd, value);
		if (stat(cmdpath, &st) == 0)
		{
			*cmd = _strdup(cmdpath);
			free(cmdpath);
			free(p);
			return (0);
		}
		free(cmdpath);
		value = _strtok(NULL, ":");
	}
	free(p);

	return (1);
}
