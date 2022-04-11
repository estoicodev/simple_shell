#include "header.h"

/**
 * write_spaces - function
 * @command: ...
 *
 * Return: 1 is success, Otherwise 0
 */
int write_spaces(char *command)
{
	int i;

	for (i = 0; command[i] == ' ' && command[i + 1] == ' '; i++)
	{}

	if (!command[i] && command[i + 1] == '\n')
		return (1);

	return (0);
}

/**
 * write_exit - function
 * @ar: ...
 *
 * Return: 1 is success, Otherwise 0
 */
int write_exit(char **ar)
{
	if (!ar)
		return (0);

	if ((_strcmp(ar[0], "exit") == 0) && ar[1] == NULL)
		return (1);

	return (0);
}

/**
 * write_env - function
 * @ar: ...
 *
 * Return: 1 is success, Otherwise 0
 */
int write_env(char **ar)
{
	if (!ar)
		return (0);

	if ((_strcmp(ar[0], "env") == 0) && ar[1] == NULL)
		return (1);

	return (0);
}
