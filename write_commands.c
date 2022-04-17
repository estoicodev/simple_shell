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

	return (0);
}

/**
 * write_exit - Find if user enter 'exit' to go out of the shell
 * @ar: ...
 * @status: ...
 *
 * Return: 0 If 'exit' don't printed
 * Otherwise, -1
 */
int write_exit(char **ar, int *status)
{
	int ex;

	if (_strcmp(ar[0], "exit") == 0 && _strlen(ar[0]) == 4)
	{
		if (ar[1] != NULL)
		{
			if (is_valid_number(ar[1]) == 1)
			{
				ex = _atoi(ar[1]);
				free_ar(ar);
				exit(ex);
			}
			else
				return (-1);
		}
		else
		{
			free_ar(ar);
			exit(*status);
		}
	}

	return (0);
}

/**
 * write_setenv - Find if user enter 'exit' to go out of the shell
 * @ar: ...
 * @av: ...
 * @cnt: ...
 * @status: ...
 *
 * Return: 1 If setenv is printed
 * If not, 0
 * If an error occurs -1
 */
int write_setenv(char **ar, char **av, int cnt, int *status)
{
	if (_strcmp(ar[0], "setenv") == 0 && _strlen(ar[0]) == 6)
	{
		if (ar[1] == NULL)
			return (1);

		if (ar[2] == NULL)
			return (1);

		if (ar[3] != NULL || setenv(ar[1], ar[2], 1) == -1)
		{
			*status = 2;
			error_set_unset_env(av[0], cnt, ar);
			return (-1);
		}

		return (1);
	}

	return (0);
}

/**
 * write_unsetenv - Find if user enter 'exit' to go out of the shell
 * @ar: ...
 * @av: ...
 * @cnt: ...
 * @status: ...
 *
 * Return: 1 If setenv is printed with all arguments
 * If not, 0
 * If an error occurs -1
 */
int write_unsetenv(char **ar, char **av, int cnt, int *status)
{
	if (_strcmp(ar[0], "unsetenv") == 0 && _strlen(ar[0]) == 8)
	{
		if (ar[1] == NULL)
			return (1);

		if (ar[2] != NULL || unsetenv(ar[1]) == -1)
		{
			*status = 2;
			error_set_unset_env(av[0], cnt, ar);
			return (-1);
		}

		return (1);
	}

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
