#include "header.h"

/**
 * count_tokens - The size of words in the string separate by space or tab
 * @str: String
 *
 * Return: The size of words
 * Otherwise, -1
 */
int count_tokens(char *str)
{
	int i, count = 0;

	for (i = 0; *str; i++)
	{
		if ((i == 0 && *str == ' ') || (i == 0 && *str == '\t'))
		{
			while (*(str + 1) == ' ' || *(str + 1) == '\t')
				str++;
		}
		else if (*str == ' ' || *str == '\t')
		{
			while (*(str + 1) == ' ' || *(str + 1) == '\t')
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
 * @delim: Delimitator
 *
 * Return: Array of each word of the string,
 * Otherwise, NULL
 */
char **split_string(char *str, char *delim)
{
	int ar_len, i = 0;
	char *copy, *token;
	char **toks;

	ar_len = count_tokens(str);

	toks = malloc((ar_len + 1) * sizeof(char *));
	if (toks == NULL)
		return (NULL);

	copy = _strdup(str);
	if (copy == NULL)
	{
		free(toks);
		return (NULL);
	}

	token = strtok(copy, delim);
	while (token != NULL)
	{
		toks[i] = _strdup(token);
		if (toks[i] == NULL)
		{
			ar_len = i;
			for (i = 0; i <= ar_len; i++)
				free(toks[i]);
			free(toks);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	toks[i] = token;
	free(copy);

	return (toks);
}
