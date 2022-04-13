#include "header.h"

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.
 * @dest: Copy from the string source
 * @src: string source
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;
	char *p_counter = src;

	len = 0;
	while (*p_counter)
	{
		len++;
		p_counter++;
	}
	for (i = 0; i <= len; i++)
	{
		*dest = *src;

		src++;
		dest++;
	}
	while (len >= 0)
	{
		dest--;
		len--;
	}
	return (dest);
}

/**
 * _strdup - desc
 * @str: desc
 *
 * Return: Pointer to the string duplicated
 */
char *_strdup(char *str)
{
	int size, i;
	char *s_array;

	if (str == NULL)
		return (NULL);

	size = 0;
	while (*(str + size))
	{
		size++;
	}

	s_array = malloc((size * sizeof(char)) + 1);

	if (s_array == NULL)
		return (NULL);

	i = 0;
	while (i < size)
	{
		*(s_array + i) = *(str + i);
		i++;
	}
	*(s_array + i) = '\0';

	return (s_array);
}
