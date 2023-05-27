#include "shell.h"

/**
 * add_env - add array of enviroment variable
 * @env: array of enviroment variable
 */

void creat_envi(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = _strdup(environ[i]);
	env[i] = NULL;
}

