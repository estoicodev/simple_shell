#include "header.h"

/**
 * validation - Validation of the command existence
 * @ar: ...
 * @paths: ...
 * @av: ...
 * @cnt: ...
 * @status: ...
 * Return: 1 If find the command
 * Otherwise 0
 */
int validation(char **ar, char **paths, char **av, int cnt, int *status)
{
	int i;
	char *abspath;

	if (paths && *(paths))
	{
		for (i = 0; paths[i] != NULL; i++)
		{
			abspath = "";
			abspath = str_concat(paths[i], ar[0]);

			if (access(abspath, X_OK) != -1)
			{
				child_process(abspath, ar, av, cnt, status);
				free(abspath);
				return (1);
			}
			free(abspath);
		}
	}

	if (access(ar[0], F_OK) == -1)
	{
		*status = 127;
		not_found(av[0], cnt, ar[0]);
	}
	else
	{
		child_process(ar[0], ar, av, cnt, status);
		return (1);
	}
	return (0);
}

/**
 * prompt - desc
 *
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
 * @status: ...
 *
 * Return: Valid string inserted by the user
 * Otherwise, NULL
 */
char *get_input(int status)
{
	char *line = NULL;
	ssize_t n;
	size_t size = 0;
	int st = status;

	n = getline(&line, &size, stdin);
	if (line == NULL)
	{
		perror("Error allocating memory");
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
		exit(st);
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
 * @av: ...
 * @cnt: ...
 * @status: ...
 *
 * Return: 1 (Find a success compare)
 * -1 for error message printed,
 * Otherwise, 0
 */
int compare_builtins(char **ar, char **av, int cnt, int *status)
{
	if (write_exit(ar, status) == -1)
	{
		*status = 2;
		ext_err(av[0], cnt, ar);
		return (-1);
	}
	else if (_strcmp(ar[0], "env") == 0 && _strlen(ar[0]) == 3)
	{
		*status = 0;
		fprintenv(environ);
		return (1);
	}

	if (write_setenv(ar, av, cnt, status) == 1)
	{
		*status = 0;
		return (1);
	}
	if (write_unsetenv(ar, av, cnt, status) == 1)
	{
		*status = 0;
		return (1);
	}
	return (0);
}

/**
 * child_process - desc
 * @first: ...
 * @ar: ...
 * @av: ...
 * @cnt: ...
 * @status: ...
 * Return: 0 (Success)
 * Otherwise, 1
 */
int child_process(char *first, char **ar, char **av, int cnt, int *status)
{
	pid_t pid;
	int sig, exit_status, res;

	if (ar == NULL)
		return (1);

	pid = fork();
	if (pid < 0)
	{
		perror(av[0]);
		return (1);
	}
	else if (pid == 0)
	{
		res = execve(first, ar, environ);
		if (res == -1)
		{
			print_error(av[0], cnt, ar[0]);
			free_ar(ar);
			*status = 126;
			exit(*status);
		}
		if (ar)
			free_ar(ar);
		exit(0);
	}
	else
	{
		waitpid(pid, &sig, WUNTRACED);

		if (WIFEXITED(sig))
		{
			exit_status = WEXITSTATUS(sig);
			*status = exit_status;
		}
	}

	return (0);
}
