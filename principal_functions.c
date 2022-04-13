#include "header.h"

/**
 * validation - Validation of the command existence
 * @ar: ...
 * @paths: ...
 * @av: ...
 * @cnt: ...
 * Return: 1 (The command exists)
 * Otherwise 0
 */
int validation(char **ar, char **paths, char **av, int cnt)
{
	int i;
	char *abspath_concat;

	for (i = 0; paths[i] != NULL; i++)
	{
		abspath_concat = "";
		abspath_concat = str_concat(paths[i], ar[0]);

		if (access(abspath_concat, X_OK) != -1)
		{
			handle_child_process(abspath_concat, ar, av, cnt);
			free(abspath_concat);
			return (1);
		}
		free(abspath_concat);
	}

	if (access(ar[0], X_OK) != -1)
	{
		handle_child_process(ar[0], ar, av, cnt);
		return (1);
	}

	return (0);
}

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
	else if (only_special_characters(line) == 1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * compare_builtins - desc
 * @ar: ...
 * @count: ...
 * Return: 1 (Find a success compare)
 * Otherwise 0
 */
int compare_builtins(char **ar, int count)
{
	write_exit(ar, count);

	if (_strcmp(ar[0], "env") == 0 && _strlen(ar[0]) == 3)
	{
		fprintenv(environ);
		return (1);
	}

	return (0);
}

/**
 * handle_child_process - desc
 * @first: ...
 * @ar: ...
 * @av: ...
 * @cnt: ...
 * Return: 1 (Success). It fails -1
 */
int handle_child_process(char *first, char **ar, char **av, int cnt)
{
	pid_t pid;
	int sig = 0;

	if (ar == NULL)
		return (-1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(first, ar, environ) == -1)
		{
			print_error(av[0], cnt, ar[0]);
			return (-1);
		}
		if (ar)
			free_ar(ar);
		exit(0);
	}
	else
	{
		wait(&sig);
	}

	return (1);
}
