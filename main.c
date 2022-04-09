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
		pid_t pid;
		char *line = NULL;
		size_t n = 0;

		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
			if (getline(&line, &n, stdin) == EOF)
			{
				free(line);
				write(STDOUT_FILENO, "\n", 1);
				break;
			}

			if (write_exit(line) == 1)
			{
				free(line);
				break;
			}

			if (_strlen(line) == 1)
			{
				free(line);
				continue;
			}

			pid = fork();
			if (pid == 0)
			{
				if (execute_basic_command(line) == 0)
					perror(av[0]);
				break;
			}
			else
				wait(NULL);
			free(line);
		}
	}
	return (0);
}
