#include "header.h"

/**
 * count_tokens - Count the words of an array with a delimitator
 * @str: String
 * @delim: Delimitator
 *
 * Return: Size of word in the string,
 * Otherwise, NULL
 */
int count_tokens(char *str, char *delim)
{
	int i = 0;
	char *copy, *token;

	if (str == NULL || delim == NULL)
		return (-1);

	copy = _strdup(str);
	token = strtok(copy, delim);
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
 * tokenizer - split string by delimitator and returns an array of each word
 * @str: String
 * @delim: Delimitator
 *
 * Return: Array of each word of the string,
 * Otherwise, NULL
 */
char **tokenizer(char *str, char *delim)
{
	int size = 0, i = 0;
	char **tokens, *aux;

	if (str == NULL || delim == NULL)
		return (NULL);

	size = count_tokens(str, delim);
	if (size == -1)
		return (NULL);

	tokens = _calloc(size + 1, sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	aux = strtok(str, delim);
	if (aux == NULL)
		return (NULL);

	while (aux != NULL)
	{
		*(tokens + i) = _calloc(1024, sizeof(char));
		_strcpy(*(tokens + i), aux);
		/**
		*(tokens + i) = str_concat(aux, "");
		*/
		aux = strtok(NULL, delim);
		i++;
	}

	if (str)
		free(str);

	return (tokens);
}
