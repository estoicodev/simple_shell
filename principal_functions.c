#include "header.h"

/**
 * validator - desc
 * @ar: ...
 * Return: ...
 */
int validator(char **ar)
{
	printf("To use the variable: %s\n", ar[0]);

	/* Aqui va la validacion del env (y mas si es necesario) */

	return (0);
}

/**
 * execution - desc
 * @ar: ...
 * Return: ...
 */
int execution(char **ar)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execute_basic_command(ar) == 0)
			return (0);
	}
	else
		wait(NULL);

	return (1);
}
