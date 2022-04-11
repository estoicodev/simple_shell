#include "header.h"

/**
 * free_ar - function that executes a basic command in the shell
 * @ar: Basic command line entered by the user
 * Return: 1 (Success). Otherwise 0
 */
void free_ar(char **ar)
{
	int i = 0;

	if (ar != NULL)
	{
		while (ar[i])
		{
			free(ar[i]);
			i++;
		}
		free(ar);
	}
}


/**
 * tokalloc - allocate memory space to the new array of tokens
 * @buffer: a string to be used to create the array of tokens
 * @delim: the delimiters to be used to separate the new tokens
 * @ctok: the number of tokens to be created
 *
 * Return: 0 if the function works succesfully, or -1 on error
 */
char **tokalloc(char *buffer, char *delim, int ctok)
{
	int i, k = 0;
	char **tokens;

	tokens = malloc((ctok + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}
	for (i = 0; i <= ctok; i++)
	{
		if (*buffer == '\0')
		{
			tokens[i] = NULL;
			break;
		}
		while (*buffer != delim[0] && *buffer != delim[1])
		{
			k++;
			buffer++;
		}
		tokens[i] = malloc((k + 1) * sizeof(char));

		if (tokens[i] == NULL)
		{
			for (; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		buffer++;
		k = 0;
	}
	return (tokens);
}

/**
 * _strtok_all - Tokenize buffers with given parameters
 * @buffer: buffer to process
 * @delimiter: string that will separate tokens
 *
 * Return: Array of tokens
 */
char **_strtok_all(char *buffer, char *delimiter)
{
	int i, j, ctok = 0, k = 0;
	char *ptr = buffer, *ptr2 = buffer;
	int size = _strlen(buffer);
	char **tokens = NULL;

	if (buffer == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (buffer[i] == delimiter[j])
				ctok++;
		}
	}
	tokens = tokalloc(ptr, delimiter, ctok);

	if (tokens == NULL)
		return (NULL);
	ptr = NULL;

	for (i = 0; i <= ctok; i++)
	{
		if (*ptr2 == '\0')
			break;
		while (*ptr2 != delimiter[0] && *ptr2 != delimiter[1])
		{
			tokens[i][k] = *ptr2;
			ptr2++;
			k++;
		}
		tokens[i][k] = '\0';
		ptr2++;
		k = 0;
	}
	ptr2 = NULL;
	return (tokens);
}
