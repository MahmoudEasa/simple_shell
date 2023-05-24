#include "main.h"


/**
 * _setenv - a function that set a env variable
 * @var_name: name of variable
 * @var_value: value of variable
 * @flag: that be zero or non-zero
 *
 * Return: on success return 0
*/

int _setenv(const char *var_name, const char *var_value, int flag)
{
	int value_len = strlen(var_value);
	int name_len = strlen(var_name), x;
	char *env_var = malloc(value_len + name_len + 2);
	if (env_var == NULL)
		return (-1);
	sprintf(env_var, "%s=%s", var_name, var_value);
	if (flag == 0 && (getenv(var_name) != NULL))
	{
		free(env_var);
		return (0);
	}
	else
	{
		x = putenv(env_var);
		if (x == -1)
		{
			free(env_var);
			return (-1);
		}
	}
	return (0);
}