#include "header.h"

/**
 * count_subcommands - The size of words in the string separate by space
 * @str: String
 *
 * Return: The size of words
 * Otherwise, -1
 */
int count_subcommands(char *str)
{
	int i, count = 0;

	for (i = 0; *str; i++)
	{
		if (i == 0 && *str == ' ')
		{
			while (*(str + 1) == ' ')
				str++;
		}
		else if (*str == ' ')
		{
			while (*(str + 1) == ' ')
				str++;
			count++;
		}
		str++;
	}
	count++;

	return (count);
}

/**
 * split_string - split string by space and returns an array of each word
 * @str: String
 *
 * Return: Array of each word of the string,
 * Otherwise, NULL
 */
char **split_string(char *str)
{
	int i, ar_len;
	char *piece, *copy;
	char **array;

	ar_len = count_subcommands(str);

	array = malloc(ar_len * sizeof(char *) + 1);
	if (array == NULL)
		return (NULL);

	copy = _strdup(str);
	if (copy == NULL)
	{
		free(array);
		return (NULL);
	}

	piece = strtok(copy, " ");
	for (i = 0; i < ar_len; i++)
	{
		array[i] = _strdup(piece);
		if (array[i] == NULL)
		{
			ar_len = i + 1;
			for (i = 0; i < ar_len; i++)
				free(array[i]);
			free(array);
			return (NULL);
		}
		piece = strtok(NULL, " ");
	}
	array[i] = NULL;
	free(piece);
	free(copy);

	return (array);
}
