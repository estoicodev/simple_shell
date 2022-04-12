#include "header.h"

/**
 * count_tokens - The size of words in the string separate by space or tab in
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
		/* Esto es para los caracteres especiales al principio */
		if (*str == '\t' || *str == ' ')
		{
			while (*(str + 1) == '\t' || *(str + 1) == ' ')
				str++;
		}

		if (*(str + 1) == '\t' || *(str + 1) == ' ')
		{
			while (*(str + 1) == '\t' || *(str + 1) == ' ')
				str++;
			count++;
		}
		str++;
	}
	count++;

	/* Esto es para validar si tiene caracter especial al final */
	if (*(str - 1) == '\t' || *(str - 1) == ' ')
		count--;

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
	char **toks;

	ar_len = count_tokens(str);

	toks = malloc((ar_len + 1) * sizeof(char *));
	if (toks == NULL)
		return (NULL);

	while ((toks[i] = strtok(str, delim)) != NULL)
	{
		str = NULL;
		i++;
	}
	return (toks);
}
