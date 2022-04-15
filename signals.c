#include "header.h"
/**
 * continue_programm - Function to handle the signal CTRL+C
 *
 * Return: void
 */
void continue_programm(int sig)
{
	(void)sig;
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		prompt();
	}
}
