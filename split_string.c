#include "header.h"

/**
 * compare_delim - Compare the delimiters "\t\n\r\a"
 * @str: String
 *
 * Return: 1 Success
 * Otherwise, 0
 */
int compare_delim(char *str)
{
	if (*str == ' ' || *str == '\t')
		return (1);

	if (*str == '\r' || *str == '\a')
		return (1);

	return (0);
}
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
		if ((i == 0 && compare_delim(str) == 1))
		{
			while (compare_delim(str + 1) == 1)
				str++;
		}

		if (compare_delim(str + 1) == 1)
		{
			while (compare_delim(str + 1) == 1)
				str++;
			count++;
		}
		str++;
	}
	count++;

	/* Esto es para validar si tiene caracter especial al final */
	if (compare_delim(str - 1) == 1)
		count--;

	return (count);
}

/**
int main(void)
{
	char *str = "ls";
	int c = count_tokens(str);

	printf("N° Tokens: %d\n", c);

	return (0);
}
*/

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
