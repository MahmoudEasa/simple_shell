#include "main.h"

/**
 * build_cmd - a function that build a Command
 * @tk: token outs of Command
 * @value:  string input
 *
 * Return: return cmd as a string
 */
char *build_cmd(char *tk, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(tk) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, tk);

	return (cmd);


}
