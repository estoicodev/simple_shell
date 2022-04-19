#include "header.h"

/**
 * write_builtins - function
 * @ar: Array of tokens
 *
 * Return: 1 If the user write a builtin
 * Otherwise 0
 */
int write_builtins(char **ar)
{
	if (_strcmp(ar[0], "exit") == 0 && _strlen(ar[0]) == 4)
		return (1);
	else if (_strcmp(ar[0], "env") == 0 && _strlen(ar[0]) == 3)
		return (1);
	else if (_strcmp(ar[0], "setenv") == 0 && _strlen(ar[0]) == 6)
		return (1);
	else if (_strcmp(ar[0], "unsetenv") == 0 && _strlen(ar[0]) == 8)
		return (1);
	else if (_strcmp(ar[0], "cd") == 0 && _strlen(ar[0]) == 2)
		return (1);
	else if (_strcmp(ar[0], "help") == 0 && _strlen(ar[0]) == 4)
		return (1);

	return (0);
}

/**
 * only_special_characters - function
 * @command: ...
 *
 * Return: 1 is success, Otherwise 0
 */
int only_special_characters(char *command)
{
	int i;

	for (i = 0; command[i] == ' ' || command[i] == '\t'; i++)
	{}

	if (command[i] == '\n')
	{
		return (1);
	}

	return (0);
}

/**
 * write_help_command - function
 * @command: ...
 *
 * Return: 1 If the user write a builtin
 * Otherwise 0
 */
int write_help_command(char *command)
{
	if (_strcmp(command, "exit") == 0 && _strlen(command) == 4)
		return (1);
	else if (_strcmp(command, "help") == 0 && _strlen(command) == 4)
		return (1);
	else if (_strcmp(command, "echo") == 0 && _strlen(command) == 4)
		return (1);
	else if (_strcmp(command, "kill") == 0 && _strlen(command) == 4)
		return (1);
	else if (_strcmp(command, "pwd") == 0 && _strlen(command) == 3)
		return (1);
	else if (_strcmp(command, "env") == 0 && _strlen(command) == 3)
		return (1);
	else if (_strcmp(command, "cd") == 0 && _strlen(command) == 2)
		return (1);
	else if (_strcmp(command, "setenv") == 0 && _strlen(command) == 6)
		return (1);
	else if (_strcmp(command, "unsetenv") == 0 && _strlen(command) == 8)
		return (1);

	return (0);
}
