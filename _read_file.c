#include "main.h"

/**
 * _read_file - a function that read command from a file
 * @filename: name of file
 * @argv: name of command
 *
 * Return: return -1 if false 0 if success
 */

void _read_file(char *filename, char **argv)
{

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": 0: ", 5);
		write(STDERR_FILENO, "Can't open ", 11);
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(127);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		trt_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);

}

