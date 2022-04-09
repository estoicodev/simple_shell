#include "header.h"

/**
 * execute_basic_command - function that executes a basic command in the shell
 * @command: Basic command line entered by the user
 * Return: 1 (Success). Otherwise 0
 */
int execute_basic_command(char *command)
{
	int res;
	char **ar = split_string(command);

	if (ar == NULL)
	{
		free(command);
		return (0);
	}

	res = execve(ar[0], ar, NULL);

	free_ar(ar);
	free(command);

	if (res == -1)
		return (0);

	return (1);
}
