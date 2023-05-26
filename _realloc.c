#include <stdlib.h>
#include <stddef.h>

int min(int size1, int size2);

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to new size
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	int i;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		free(ptr);

		if (!p)
			return (NULL);
	}

	else if (new_size == old_size)
		return (ptr);

	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		p = malloc(new_size);

		if (!ptr)
			return (NULL);

		for (i = 0; i < min(new_size, old_size); i++)
			*((char *)p + i) = *((char *)ptr + i);

		free(ptr);

	}

	return (p);
}

/**
 * min - return minimum size
 * @size1: number 1
 * @size2: number 2
 *
 * Return: minimum size.
 */

int min(int size1, int size2)
{
	return (size1 < size2 ? size1 : size2);
}

