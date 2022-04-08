#include "header.h"

/**
 * write_exit - function
 * @command: ...
 *
 * Return: 1 is success, Otherwise 0
 */
int write_exit(char *command)
{
	char *token = strtok(command, " ");

	if (!token)
		return (0);

	if (_strcmp(token, "exit") == 0 && _strlen(token) == 4)
	{
		free(command);
		return (1);
	}
	return (0);
}
/**
 * last_newline_to_null - function
 * @command: ...
 *
 * Return: void
 */
void last_newline_to_null(char *command)
{
	if (command[_strlen(command) - 1] == '\n')
		command[_strlen(command) - 1] = '\0';
}
