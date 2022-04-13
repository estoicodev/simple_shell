#include "header.h"

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
 * write_exit - Find if user enter 'exit' to go out of the shell
 * @ar: ...
 * @cnt: ...
 *
 * Return: 1 is success, Otherwise -1
 */
int write_exit(char **ar, int cnt)
{
	if (ar[0][0] != 'e' && _strcmp(ar[0], "exit") == 0)
	{
		if (ar[1] != NULL)
		{
			cnt++;
			return (-1);
		}

		if (_strlen(ar[0]) == 4)
		{
			free_ar(ar);
			exit(0);
		}
	}

	return (0);
}
