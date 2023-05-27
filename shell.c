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

	signal(SIGINT, signal_to_handel);

	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();

		input = _getline();
		if (input[0] == '\0')
			continue;

		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
			exit_bul(cmd, input, argv, counter);
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free_all(cmd, input);
			continue;
		}
		else
			st = check_cmd(cmd, input, counter, argv);
		free_all(cmd, input);
	}
	return (statue);
}

