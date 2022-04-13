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

	if (*(ar + i))
		for (i = 0; *(ar + i); i++)
			printf("array[%d] = \"%s\"\n", i, *(ar + i));
}

/**
 * _calloc - desc
 * @nmemb: desc
 * @size: desc
 *
 * Return: void pointer.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
	{
		*(ptr + i) = 0;
	}

	return ((void *)ptr);
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

