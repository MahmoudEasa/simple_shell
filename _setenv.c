#include "main.h"

/**
 * _setenv_ - a function that set or update new env var
 * @var_name: name of variable
 * @new_value: value of variable
 * @flag: a flag is zero or none_zero
 *
 * Return: return 0 or -1
*/

int _setenv_(char *var_name, char *new_value, int flag)
{
	char **env = environ;
	char **new_env, *new_var;
	int i, len, found = 0;

	(void)new_env;
	len = strlen(var_name);
	if (flag != 0)
	for (i = 0; env[i] != NULL ; i++)
	{
		if ((_strncmp(env[i], var_name, len) == 0) && env[i][len] == '=')
		{
			found = 1;
			new_var = concat(var_name, new_value);
			if (new_var == NULL)
			{
				perror("Error");
				return (-1);
			}
			_strcpy(env[i], new_var);
			free(new_var);
			break;
		}
	}
	if (found == 0)
		found_fun(var_name, new_value);

	return (0);
}

/**
 * found_fun - a function that call when fount env variable
 * @var_name: name of variable
 * @new_value: value of variable
 *
 * Return: return 0 if success else return -1
*/
int found_fun(char *var_name, char *new_value)
{
	char *new_var, **new_env, **env = environ;
	int env_count, i;

	new_var = concat(var_name, new_value);
	if (!new_var)
	{
		perror("Error");
		return (-1);
	}
	env_count = environ_size(env);
	new_env = malloc(sizeof(char *) * (env_count + 2));
	if (!new_env)
	{
		perror("Error");
		free(new_var);
		return (-1);
	}
	for (i = 0; env[i]; i++)
	{
		new_env[i] = malloc(strlen(env[i]));
		if (!new_env[i])
			return (-1);
		_strcpy(new_env[i], env[i]);
	}
	new_env[i] = malloc(sizeof(char) * strlen(new_var));
	if (!new_env[i])
		return (-1);
	_strcpy(new_env[i], new_var);
	free(new_var);
	new_env[i + 1] = NULL;
	environ = new_env;
	return (0);
}
/**
 * concat - a function that concat two strings
 * @var_name: name of variable
 * @new_value: value of variable
 *
 * Return: return string
*/
char *concat(char *var_name, char *new_value)
{
	int len1 = _strlen(var_name);
	int len2 = _strlen(new_value);
	char *result = malloc(len1 + len2 + 2);

	if (!result)
		return (NULL);
	_strcpy(result, var_name);
	_strcat(result, "=");
	_strcat(result, new_value);
	return (result);
}

/**
 * environ_size - a function the size of environ
 * @env: a environ input
 *
 * Return: return a count
*/
int environ_size(char **env)
{
	int count = 0;

	while (env[count])
		count++;
	return (count);
}
