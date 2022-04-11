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
