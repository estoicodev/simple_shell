#include "header.h"

/**
 * only_spaces - function
 * @command: ...
 *
 * Return: 1 is success, Otherwise 0
 */
int only_spaces(char *command)
{
	int i;

	for (i = 0; command[i] == ' '; i++)
	{}

	if (command[i] == '\n')
	{
		return (1);
	}

	return (0);
}

char *start_spaces(char *command)
{
	int i, j;

	for (i = 0; command[i] == ' ' || command[i] == '\t'; i++)
	{}

	if (command[i] != '\n')
	{
		for (j = 0; j < i; j++)
		{
			command++;
		}
		return (command);
	}

	return (command);
}

/**
int main(void)
{
	char *str = "  exit";

	printf("%s\n", str);
	str = start_spaces(str);
	printf("%s\n", str);

	return (0);
}
*/
