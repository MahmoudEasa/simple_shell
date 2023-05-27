#include "main.h"

/**
* _getline - a function that read line from user
*
* Return: return input string
*/

char *_getline()
{
	int i, len = BUFSIZE, r_bytes;
	char ch = 0, *buffer = malloc(len);

	if (!buffer)
		return (NULL);

	for (i = 0; ch != EOF && ch != '\n'; i++)
	{
		fflush(stdin);
		r_bytes = read(STDIN_FILENO, &ch, 1);
		if (r_bytes == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
			buffer[i] = ch;
			if (buffer[0] == '\n')
			{
				free(buffer);
				return ("\0");
			}
			if (i >= len)
			{
				buffer = _realloc(buffer, len, len + 1);
				if (!buffer)
					return (NULL);
			}
	}
	buffer[i] = '\0';
	hashtag_handle(buffer);
	return (buffer);
}


/**
 * hashtag_handle - remove everything after #
 * @buff: input;
 * Return:void
 */
void hashtag_handle(char *buff)
{
	int i;

		for (i = 0; buff[i] != '\0'; i++)
		{
			if (buff[i] == '#')
			{
			buff[i] = '\0';
			break;
			}
	}
}
