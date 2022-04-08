#include "header.h"

/**
 * execute_basic_command - function that executes a basic command in the shell
 * @command: Basic command line entered by the user
 *
 * Return: 0 (Success). Otherwise -1
 */
int execute_basic_command(char *command)
{
	int res;
	char **ar_tokens = split_string(command);
	char *first = ar_tokens[0];

	if (ar_tokens == NULL)
	{
		free(command);
		return (-1);
	}

	res = execve(first, ar_tokens, NULL);

	free(ar_tokens);
	free(first);
	free(command);

	if (res == -1)
	{
		return (-1);
	}

	return (0);
}
