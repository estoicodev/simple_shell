#include "header.h"

/**
 * validation - get and tokenizes paths
 * @ar: ...
 * @paths: ...
 * Return: void
 */
int validation(char **ar, char **paths)
{
        int i;
        char *abspath_concat = "";

        for (i = 0; paths[i] != NULL; i++)
        {
                abspath_concat = _strcat(paths[i], ar[0]);

                if (access(abspath_concat, X_OK) != -1)
                {
                        ar[0] = abspath_concat;
                        return (1);
                }
		free(abspath_concat);
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

