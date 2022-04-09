#include "header.h"

/**
 * free_ar - function that executes a basic command in the shell
 * @ar: Basic command line entered by the user
 * Return: 1 (Success). Otherwise 0
 */
void free_ar(char **ar)
{
	int i = 0;

	if (ar != NULL)
	{
		while (ar[i])
		{
			free(ar[i]);
			i++;
		}
		free(ar);
	}
}

/**
 * debug - function that debuggs line and ar
 * @line: Basic command line entered by the user
 * @ar: Basic command line entered by the user
 * Return: 1 (Success). Otherwise 0
 */
void debug(char *line, char **ar)
{
	printf("line = %s\n", line);
	printf("ar[0] = %s\n", ar[0]);
}
