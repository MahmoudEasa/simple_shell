#include "main.h"

/**
 * path_cmd -  a function that find full path in env
 * @cmd: command line
 * Return: return 1 if failure 0 if success
 */
int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build_cmd(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);

	return (1);
}
