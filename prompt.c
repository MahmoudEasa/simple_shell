#include "main.h"

/**
 * prompt - display a prompt and wait for the user to type a command
 * @buf: pointer to buffer
 */

void prompt(char **buf)
{
	int is_atty = isatty(STDIN_FILENO);
	size_t buf_size = 30;

	if (is_atty)
		printf("($) ");
	if (_getline(buf, &buf_size, stdin) == -1)
	{
		if (is_atty)
			printf("\n");
		exit(EXIT_SUCCESS);
	}
}

