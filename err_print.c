/**
 * err_print - print error when command fail
 * @line: command line
 * @count: loops count
 * @av: name of command
 */


void err_print(char *line, int count, char **av)
{
	char *error;

	PRINTER(av[0]);
	PRINTER(": ");
	error = _itoa(count);
	PRINTER(error);
	free(error);
	PRINTER(": ");
	PRINTER(line);
	PRINTER(": not found\n");
}
