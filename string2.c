#include "header.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Print a string
 * @str: String
 *
 * Return: void
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}

/**
 * _strchr - desc
 * @s: desc
 * @c: desc
 *
 * Return: desc
 */
char *_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (!*s++)
		{
			return (NULL);
		}
	}

	return (s);
}

/**
 *  _strncat - concatenates two strings with n bytes of src.
 * @dest: First string
 * @src: Second string (concatenate to dest)
 * @n: Number of bytes concatenated of src
 * Return: The string concatenated
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i]; i++)
	{}

	for (j = 0; src[j] != src[n]; j++)
	{
		dest[i] = src[j];
		i++;
	}

	return (dest);
}

/**
 * _strncmp - compares some bytes of two strings
 * @s: a string
 * @t: a string
 * @n: the number of bytes to be compared
 *
 * Return: the result of the comparations in both strings
 */
int _strncmp(char *s, char *t, int n)
{
	int dif = 0;
	char *s1 = s, *s2 = t;

	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n > 0)
	{
		s1++;
		s2++;
		n--;
	}

	if (*s1 != '\0' && *s2 != '\0')
		dif = *s1 - *s2;
	s1 = NULL;
	s2 = NULL;

	return (dif);
}
