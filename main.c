#include "header.h"

/**
 * main - main function
 * @ac: ...
 * @av: arguments of the programm
 * Return: 0 is success, Otherwise 1
 */
int main(int ac __attribute__ ((unused)), char *av[])
{
	while (1)
	{
		char *line = NULL, **ar;
		pid_t pid;

		prompt();

		line = get_input();
		if (!line)
			continue;

		ar = split_string(line, " \n");

		if (write_env(ar) == 1)
			fprintenv(environ);

		if (_strcmp(ar[0], "env") != 0)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execute_basic_command(ar) == 0)
				{
					free(line);
					perror(av[0]);
					break;
				}
			}
			else
				wait(NULL);
		}
		free_ar(ar);
		free(line);
	}
	return (0);
}
