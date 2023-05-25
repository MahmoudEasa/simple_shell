#include "main.h"

/**
 * print_env - print environment
 * @env: array of aenvironment
 */

void print_env(char **env)
{
	char **envp = environ;
	(void)env;

	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
}

