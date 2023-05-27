#include "main.h"

/**
 * his_dis - a function that display History
 * @ch: character input
 * @st: status
 * Return: return 0 if success -1 if false
 */

int his_dis(char **ch, int st)
{
	char *name_file = ".simple_shell_history", *line = NULL, *err;
	FILE *fp;
	size_t len = 0, count = 0;

	(void)ch;
	(void)st;

	fp = open(filename, O_RDONLY);
	if (!fp)
	return (-1);
	while ((getline(&line, &len, fp)) != -1)
	{
		count++;
		err = _itoa(count);
		PRINTER(err);
		free(err);
		PRINTER(" ");
		PRINTER(line);
	}
	if (line)
		free(line);
	close(fp);
	return (0);
}

