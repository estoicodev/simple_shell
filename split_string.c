#include "header.h"

/**
 * count_toks - Count the words of an array with a delimitator
 * @str: String
 * @delim: Delimitator
 *
 * Return: Size of word in the string,
 * Otherwise, NULL
 */
int count_toks(char *str, char *delim)
{
	int i = 0;
	char *copy = _strdup(str);
	char *token = strtok(copy, delim);

	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delim);
	}

	if (copy)
		free(copy);

	return (i);
}
/**
int main(void)
{
        int count = 0;
        char *path = _getenv("PATH");

        if (path)
                printf("%s\n", path);
        else
                printf("Doesn't exist the env var\n");

        count = count_toks(path, ":");

        printf("%s\n", path);

        if (count > 0)
                printf("Count: %d\n", count);
        else
                printf("The env var is empty\n");

        if (path)
                free(path);

        return (0);
}
*/

/**
 * split_string - split string by delimitator and returns an array of each word
 * @str: String
 * @delim: Delimitator
 *
 * Return: Array of each word of the string,
 * Otherwise, NULL
 */
char **split_string(char *str, char *delim)
{
	int len, i = 0;
	char **tokens;

	len = count_toks(str, delim);

	tokens = malloc((len + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	while ((tokens[i] = strtok(str, delim)) != NULL)
	{
		str = NULL;
		i++;
	}
	tokens[i] = NULL;

	if (str)
		free(str);

	print_ar(tokens);
	printf("------------------------------------\n");

	return (tokens);
}

/**
int main(void)
{
	char *line = NULL;
	ssize_t n;
	size_t size = 0;
	char **ar;

	n = getline(&line, &size, stdin);

	ar = split_string(line, " \t\n");

	return (0);
}
*/

/**
int main(void)
{
	char *delim = ":";
	char **ar;
	int i = 0;
	// char str[] = "hola:como:estas:soy:mauricio";
	char *str = _getenv("PATH");

	printf("Line: \"%s\"\n", str);
	printf("Delimiter: \"%s\"\n", delim);

	ar = split_string(str, delim);
	if (ar)
	{
		print_ar(ar);
		free(ar);
	}

	// El getline hace malloc y al terminar de usar la linea del getline hacer free al str
	if (str)
		free(str);

	return (0);
}
*/
