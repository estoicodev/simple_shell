#include "header.h"

/**
 * write_a_builtin - function
 * @command: ...
 *
 * Return: 1 If the user write a builtin
 * Otherwise 0
 */
int write_a_builtin(char *command)
{
	if (_strcmp(command, "exit") == 0 && _strlen(command) == 4)
		return (1);
	else if (_strcmp(command, "env") == 0 && _strlen(command) == 3)
		return (1);
	else if (_strcmp(command, "setenv") == 0 && _strlen(command) == 6)
		return (1);
	else if (_strcmp(command, "unsetenv") == 0 && _strlen(command) == 8)
		return (1);
	else if (_strcmp(command, "cd") == 0 && _strlen(command) == 2)
		return (1);
	else if (_strcmp(command, "help") == 0 && _strlen(command) == 4)
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
