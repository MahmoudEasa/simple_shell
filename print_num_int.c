#include "main.h"

/**
 * print_num_int - a function that print integer number
 * @num: print int num
*/

void print_num_int(int num)
{
	unsigned int j = num;

	if (num < 0)
	{
		_putchar('-');
		j = -j;
	}
	if ((j / 10) > 0)
		print_num(j / 10);

	_putchar(j % 10 + '0');
}

