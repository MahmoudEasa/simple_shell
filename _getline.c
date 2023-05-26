#include "main.h"

/**
 * _getline - a function that read line
 * @lineptr: line pointer
 * @n: n size
 * @stream: a file input
 * Return: return number
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t r_bytes, len;
	char *buffer = NULL;

	if (!lineptr || !n)
		return (-1);
	buffer = *lineptr;
	len = (ssize_t) *n;
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * len);
		if (!buffer)
			return (-1);
	}
	if (fgets(buffer, len, stream) != NULL)
	{
		r_bytes = _strlen(buffer);
		if (buffer[r_bytes - 1] != '\n')
			resize_buf(&buffer, &r_bytes, len, stream);
		else
		{
			_strcpy((*lineptr), buffer);
			return (r_bytes);
		}
	}
	else
	{
		free(buffer);
		return (-1);
	}
	return (-1);
}

/**
 * resize_buf - a function that resize a buffer
 * @buffer: input string
 * @r_bytes: number of bytes that read
 * @len: length of buffer
 * @stream: a file input
*/

void resize_buf(char **buffer, ssize_t *r_bytes, ssize_t len, FILE *stream)
{
	while ((*r_bytes = len - 1) && *buffer[*r_bytes - 1] != '\n')
	{
		len *= 2;
		*buffer = _realloc(*buffer, *r_bytes, len);
		if (!(*buffer))
		{
			free(*buffer);
			exit(EXIT_FAILURE);
		}
		if (fgets(((*buffer) + (*r_bytes)), (len - (*r_bytes)), stream) != NULL)
			*r_bytes += _strlen(*buffer);
		else
			break;
	}
}

