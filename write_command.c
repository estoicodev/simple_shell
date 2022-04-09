#include "header.h"

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
	token = strtok(copy, " ");

	if (_strcmp(token, "exit\n") == 0 && _strlen(token) == 5)
	{
		free(copy);
		return (1);
	}
	free(copy);

	return (0);
}
