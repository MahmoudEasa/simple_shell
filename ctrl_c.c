#include "main.h"

/**
 * ctrl_c - handle ^C
 * @sig: int
 */

void ctrl_c(int sig)
{
	if (sig == SIGINT)
		PRINTER("\n$ ");
}

