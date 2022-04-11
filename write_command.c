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
 * @command: ...
 *
 * Return: 1 is success, Otherwise 0
 */
int write_exit(char *command)
{
	char *copy;
	char *token;

	if (!command)
		return (0);

	copy = _strdup(command);
	token = strtok(copy, " \n");

	if (_strcmp(token, "exit") == 0 && _strlen(token) == 4)
	{
		free(copy);
		return (1);
	}
	free(copy);

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
	if ((_strcmp(ar[0], "env") == 0) && ar[1] == NULL)
		return (1);

	return (0);
}
