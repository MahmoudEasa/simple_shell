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
		write(STDOUT_FILENO, *envp, _strlen(*envp));
		write(STDOUT_FILENO, "\n", 1);
		envp++;
	}
}

