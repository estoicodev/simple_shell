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

	size = count_tokens(str, delim);

	tokens = _calloc(size + 1, sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	aux = strtok(str, delim);
	while (aux != NULL)
	{
		tokens[i] = str_concat(aux, "");
		aux = strtok(NULL, delim);
		i++;
	}

	if (str)
		free(str);

	return (tokens);
}

/**
int main(void)
{
	char delim[] = " \t";
	char **ar;
	int i = 0, size = 0;
	char str[] = " \tholacomo\t mellamomauricio dewf we wew";

	printf("Line: \"%s\"\n", str);
	printf("Len: %d\n", _strlen(str));
	printf("Delimiter: \"%s\"\n", delim);
	printf("-----------------\n");

	size = count_tokens(str, delim);

	ar = tokenizer(str, delim);

	printf("ar[0] = %s\n", ar[0]);
	printf("Address = %p\n", ar[0]);
	printf("str = %s\n", str);
	printf("Address = %p\n", str);

	if (!ar)
		return (1);

	print_ar(ar);
	free_ar(ar);

	return (0);
}
*/
