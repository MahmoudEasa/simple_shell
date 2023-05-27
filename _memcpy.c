#include "main.h"

/**
 * _memcpy - copy byte
 * @dest: string
 * @src: string
 * @n: unsigned int
 *
 * Return: pointer void
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

