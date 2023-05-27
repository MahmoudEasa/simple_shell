#include "main.h"

/**
 * print_num - a function that print a num
 * @num: an input number that printed
 */
void print_num(unsigned int num)
{
	unsigned int y = num;

	if ((y / 10) > 0)
		print_num(y / 10);

	_putchar(y % 10 + '0');

}
