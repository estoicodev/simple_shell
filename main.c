#include "header.h"

/**
 * main - main function
 *
 * Return: 0 is success, Otherwise 1
 */
int main(void)
{
	while (1)
	{
		pid_t pid;
		char *line = NULL;
		size_t n = 0;

		write(STDOUT_FILENO, "$ ", 2);
		if (getline(&line, &n, stdin) == -1)
			return (1);
		last_newline_to_null(line);

		if (write_exit(line) == 1)
			break;

		if (line[0] != '\0')
		{
			pid = fork();
			if (pid == 0)
			{
				if (execute_basic_command(line) == -1)
					perror("Could not execute rexc");
				break;
			}
			else
				wait(NULL);
		}
		free(line);
	}
	return (0);
}
