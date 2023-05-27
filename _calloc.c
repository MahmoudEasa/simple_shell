#include "shell.h"

/**
 * _calloc -  allocate memory
 * @size: size
 *
 * Return: pointer void
 */

void *_calloc(unsigned int size)
{
	unsigned int i;
	char *a;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		a[i] = '\0';
	return (a);
}

