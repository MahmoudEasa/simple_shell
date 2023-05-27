#include "main.h"

/**
 * fill_array - fill array
 * @ptr: pointer void
 * @el: int
 * @len: unsigned int
 *
 * Return: Void Pointer
 */

void *fill_array(void *a, int el, unsigned int len)
{
	unsigned int i = 0;
	char *p = a;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

