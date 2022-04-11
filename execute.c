#include "header.h"

/**
 * execute_basic_command - function that executes a basic command in the shell
 * @ar: Basic command line entered by the user
 * Return: 1 (Success). Otherwise 0
 */
int execute_basic_command(char **ar)
{
	int res;

	if (ar == NULL)
		return (0);

	res = execve(ar[0], ar, environ);

	if (res == -1)
	{
		free_ar(ar);
		return (0);
	}
	free_ar(ar);
	return (1);
}
