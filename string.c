#include "header.h"

/**
 * _strlen - Returns the length of a string
 * @s: String
 * Return: void
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}

	return (i);
}

/**
 * str_concat - desc
 * @s1: desc
 * @s2: desc
 *
 * Return: String.
 */
char *str_concat(char *s1, char *s2)
{
	int size_s1, size_s2, i, j;
	char *p_s1, *p_s2, *new_s;

	if (s1 == NULL)
		p_s1 = "";
	else
		p_s1 = s1;

	if (s2 == NULL)
		p_s2 = "";
	else
		p_s2 = s2;

	for (size_s1 = 0; *(p_s1 + size_s1); size_s1++)
	{}

	for (size_s2 = 0; *(p_s2 + size_s2); size_s2++)
	{}

	new_s = malloc((size_s1 + size_s2) * sizeof(char) + 1);

	if (new_s == NULL)
		return (NULL);

	for (i = 0; i < size_s1; i++)
	{
		*(new_s + i) = *(p_s1 + i);
	}

	for (j = 0; j < size_s2; j++)
	{
		*(new_s + i + j) = *(p_s2 + j);
	}

	*(new_s + i + j) = '\0';

	return (new_s);
}

/**
 * _strcmp - compares two strings.
 * @s1: First string
 * @s2: Second string
 * Return: If both strings are equal returns 0.
 * If the matching character of left string has greater ASCII value than the
 * character of the right string returns a value greater than zero.
 * If the matching character of left string has lesser ASCII value than the
 * character of the right string returns a value less than zero.
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int len_s1;
	char *p_s1 = s1;

	len_s1 = 0;
	while (*p_s1)
	{
		p_s1++;
		len_s1++;
	}
	for (i = 0; i < len_s1; i++)
	{
		if (*s1 != *s2)
		{
			if (*s1 > *s2)
			{
				return (*s1 - *s2);
			}
			else if (*s2 > *s1)
			{
				return (*s1 - *s2);
			}
		}
		s1++;
		s2++;
	}
	return (0);
}
