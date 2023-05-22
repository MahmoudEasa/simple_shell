#include "main.h"

/**
 * prompt - display a prompt and wait for the user to type a command
 * @buf: pointer to buffer
 */

void prompt(char **buf)
{
	int is_atty = isatty(STDIN_FILENO);

	if (is_atty)
		printf("#cisfun$ ");
	if (fgets(*buf, 1024, stdin) == NULL)
	{
		if (feof(stdin))
		{
			if (is_atty)
				printf("\n");
			free(*buf);
			exit(EXIT_SUCCESS);
		}

		perror("Error ");
		*buf = NULL;
	}
}

