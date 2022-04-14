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
	int count = 0, res;
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

		res = compare_builtins(ar);
		if (res != 0)
			count++;
		if (res == -1)
		{
			ext_err(av[0], count, ar);
			free_ar(ar);
			continue;
		}

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
