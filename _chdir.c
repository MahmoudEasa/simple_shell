#include "main.h"

/**
 * _chdir - change dir
 * @cmd: array
 * @er: int
 *
 * Return: 0 succes 1 failed
 */

int _chdir(char **cmd, int er)
{

	int value = -1;
	char cwd[PATH_MAX];

	(void)cmd;
	(void)er;
	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		if (cmd[1])
			value = chdir(cmd[1]);
	if (value == -1)
	{
		perror("hsh");
		free_env(cmd);
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		_setenv_("OLDPWD", getenv("PWD"), 1);
		_setenv_("PWD", cwd, 1);
	}
	return (0);
}

