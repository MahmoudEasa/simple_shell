#include "shell.h"

/**
 * _itoa - convert integer
 * @n: int
 *
 * Return: char
 */

char *_itoa(unsigned int n)
{
	char *s;
	int len = 0, i = 0;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * array_rev - reverse array
 * @arr: array
 * @len: int
 */

void array_rev(char *arr, int len)
{
	char tmp;
	int i;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * intlen - length of int
 * @num: given int
 * Return: length of int
 */

int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
