#include "shell.h"

/**
 * free_env - free envirnoment
 * @env:  environment variables.
 */

void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		free(env[i]);
}

