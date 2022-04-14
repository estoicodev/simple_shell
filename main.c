#include "header.h"

/**
 * main - main function
 * @ac: ...
 * @av: arguments of the programm
 * Return: 0 is success, Otherwise 1
 */
int main(int ac __attribute__ ((unused)), char *av[])
{
	char *line = NULL, **paths, **ar;
	int count = 0;
	signal(SIGINT, continue_programm);
	while (1)
	{
		prompt();

		line = get_input();
		if (line == NULL)
		{
			count++;
			continue;
		}

		ar = tokenizer(line, " \t\n");

		if (compare_builtins(ar, count) == 1)
			count++;

		if (_strcmp(ar[0], "env") != 0)
		{
			count++;
			paths = get_PATHS();
			if (validation(ar, paths, av, count) == 0)
				print_error(av[0], count, ar[0]);
			free_ar(paths);
		}
		free_ar(ar);
	}
	return (0);
}
