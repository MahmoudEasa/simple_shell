#include "main.h"

/**
 * prompt - display a prompt and wait for the user to type a command
 * @buf: pointer to buffer
 */

void prompt(char **buf, ssize_t fd)
{
<<<<<<< HEAD
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
=======
	int is_atty = isatty(STDIN_FILENO);
	size_t buf_size = 1024;
	ssize_t nread;

	if (fd)
	{
		if ((nread = read(fd, *buf, sizeof(*buf))) <= 0)
		{
			if (is_atty)
				write(STDOUT_FILENO, "\n", 1);
			close(fd);
			free(*buf);
			exit(EXIT_SUCCESS);
		}
/*		printf("\nfile after: %s\n", *buf);*/
	}
	else
	{

>>>>>>> 68f5d118263ddb494bdb29c5322a5c5c2b7f6862
		if (is_atty)
			write(STDOUT_FILENO, " ($) ", 5);
		if (_getline(buf, &buf_size, stdin) == -1)
		{
			if (is_atty)
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
	}
}

