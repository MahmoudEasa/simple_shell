#include "main.h"
/**
 * trt_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * Return : Excute A line void
 */
void trt_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = split_str(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			exit_file(cmd, line, fp);
		}
		else if (check_buil(cmd) == 0)
		{
			st = handle_buil(cmd, st);
			free(cmd);
		}
		else
		{
			st = exe_cmd(cmd, line, counter, argv);
			free(cmd);
		}
}
