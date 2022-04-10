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
		char *line = NULL;
		size_t n = 0;
		char **ar;
		pid_t pid;

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

			ar = split_string(line);

			/* Aqui falta el validator */

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
			free_ar(ar);
			free(line);

		}
		else
		{
			/* Aqui se maneja el modo no interactivo */
		}
	}
	return (0);
}
