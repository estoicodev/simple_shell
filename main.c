#include "header.h"

/**
 * main - main function
 * @ac: ...
 * @av: arguments of the programm
 * Return: 0 is success, Otherwise 1
 */
int main(int ac __attribute__ ((unused)), char *av[])
{
	char *line = NULL, **ar;
	int count = 0;

	while (1)
	{
		prompt();

		line = get_input();
		if (line == NULL)
		{
			count++;
			continue;
		}

		ar = split_string(line, " \t\n");

		if (compare_builtins(ar, line) == 1)
			count++;

		if (_strcmp(ar[0], "env") != 0)
		{
			count++;
			if (validation(ar, get_PATHS()) == 0)
			{
				print_error(av[0], count, ar[0]);
				free_ar(ar);
			}
			else
			{
				handle_child_process(ar, av);
			}
		}
	}
	return (0);
}
