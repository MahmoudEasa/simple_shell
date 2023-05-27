#include "main.h"

/**
 * cmd_path -  a function that find full path in env
 * @cmd: command line
 * Return: return 1 if failure 0 if success
 */
int cmd_path(char **cmd)
{
	struct stat st;
	char *p, *value, *cmd_path;

	p = _getenv("PATH");
	value = _strtok(p, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &st) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(p);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(p);

	return (1);
}
