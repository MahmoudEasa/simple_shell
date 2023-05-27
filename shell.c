#include "shell.h"

/**
 * main - simple shell
 * @argc: arg count
 * @argv: arg val
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	int counter = 0, statue = 1, st = 0;
	char *input, **cmd;
	(void)argc;

	if (argv[1] != NULL)
		read_file(argv[1], argv);

	signal(SIGINT, ctrl_c);

	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();

		input = _getline();
		if (input[0] == '\0')
			continue;

		ndle_history(input);
		cmd = split_str(input);
		if (_strcmp(cmd[0], "exit") == 0)
			exit_p(cmd, input, argv, counter);
		else if (check_buil(cmd) == 0)
		{
			st = handle_buil(cmd, st);
			_free(cmd, input);
			continue;
		}
		else
			st = exe_cmd(cmd, input, counter, argv);
		_free(cmd, input);
	}
	return (statue);
}

