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
		exit(EXIT_FAILURE);
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

