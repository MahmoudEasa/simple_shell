#include "main.h"

/**
 * prompt - display a prompt and wait for the user to type a command
 * @buf: pointer to buffer
 */

void prompt(char **buf)
{
	int is_atty = isatty(STDIN_FILENO);
	size_t buf_size = 1024;

	if (is_atty)
		write(STDIN_FILENO, " ($) ", 5);
	if (_getline(buf, &buf_size, stdin) == -1)
	{
		if (is_atty)
			write(STDIN_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}

