#include "main.h"

/**
 * prompt - display a prompt and wait for the user to type a command
 * @buf: pointer to buffer
 */

void prompt(char **buf)
{
	size_t is_atty = isatty(STDIN_FILENO);
	size_t buf_size = 0;
	ssize_t r_bytes;

	if (is_atty)
		write(STDIN_FILENO, " ($) ", 5);
	
	r_bytes = _getline(buf, &buf_size, stdin);

	if (r_bytes == -1)
	{
		perror("Error (getline)");
		free(*buf);
		if (is_atty)
			write(STDIN_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}

