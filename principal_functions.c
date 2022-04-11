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
 * handle_child_process - desc
 * @ar: ...
 * @av: ...
 * @cnt: ...
 * Return: 1 (Success). It fails -1
 */
int handle_child_process(char **ar, char **av, int cnt)
{
	pid_t pid;

	if (ar == NULL)
		return (-1);

	pid = fork();
	if (pid < 0)
	{
		perror(av[0]);
		free_ar(ar);
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(ar[0], ar, environ) == -1)
		{
			print_error(av[0], cnt, ar[0]);
			free_ar(ar);
			exit(1);
		}
		free_ar(ar);
		exit(0);
	}
	else
	{
		wait(NULL);
	}

	return (1);
}
