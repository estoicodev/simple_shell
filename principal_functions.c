#include "header.h"

/**
 * prompt - desc
 * Return: void
 */
void prompt(void)
{
	char *pr = "$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, pr, _strlen(pr));
}

/**
 * get_input - desc
 * Return: Input string
 */
char *get_input(void)
{
	char *line = NULL;
	ssize_t n;
	size_t size = 0;

	n = getline(&line, &size, stdin);
	if (line == NULL)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}
	else if (n == 1)
	{
		free(line);
		return (NULL);
	}
	else if (n == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(0);
	}
	else if (write_exit(line) == 1)
	{
		free(line);
		exit(0);
	}
	return (line);
}

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
