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
		char *line = NULL;
		size_t n = 0;
		ssize_t r;
		pid_t pid;
		int rexc;
		char *cmd;
		char **ar_tokens;

		write(1, "$ ", 2);
		r = getline(&line, &n, stdin);
		if (r == -1)
			return (1);

		if (line[r - 1] == '\n')
			line[r - 1] = '\0';

		if (strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}

		if (strcmp(line, "\0") != 0)
		{
			pid = fork();
			if (pid == 0)
			{
				ar_tokens = split_string(line);
				cmd = _strdup("/bin/");
				_strcat(cmd, ar_tokens[0]);
				rexc = execve(cmd, ar_tokens, NULL);
				if (rexc == -1)
					perror("Could not execute rexc");
			}
			else
				wait(NULL);
		}
		free(line);
	}
	return (0);
}
