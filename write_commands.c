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
