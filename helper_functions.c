#include "header.h"

/**
 * free_ar - function that executes a basic command in the shell
 * @ar: Array of strings
 * Return: void
 */
void free_ar(char **ar)
{
	int i = 0;

	if (ar != NULL)
	{
		while (*(ar + i))
		{
			free(*(ar + i));
			i++;
		}
		free(ar);
	}
}

/**
 * print_ar - Print each element of an array of strings of strings
 * @ar: Array of strings
 * Return: void
 */
void print_ar(char **ar)
{
        int i = 0;

        for (i = 0; *(ar + i); i++)
                printf("array[%d] = \"%s\"\n", i, *(ar + i));
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
		return (NULL);

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
			free_ar(tokens);
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

/**
 * _strcat - concatenates two strings.
 * @dest: First string
 * @src: Second string
 * Return: String after concatenation
 */
char *_strcat(char *dest, char *src)
{
	int len;
	int i;

	len = 0;

	while (*dest)
	{
		dest++;
		len++;
	}

	for (i = 0; *(src + i); i++)
	{
		*dest = *(src + i);
		dest++;
		len++;
	}

	*dest = '\0';

	while (len > 0)
	{
		dest--;
		len--;
	}

	return (dest);
}

