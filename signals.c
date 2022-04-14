#include "header.h"

void continue_programm(int sig)
{
	(void)sig;
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		prompt();
	}
}
