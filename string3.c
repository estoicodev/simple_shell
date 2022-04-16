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

/**
 * _atoi - Converts an string to an integer
 * @s: String to be converted
 *
 * Return: Integer
 */
int _atoi(char *s)
{
	int i, minus, res, flag;

	res = 0;
	flag = 0;
	minus = -1;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (*(s + i) == '-')
			minus *= -1;

		if (*(s + i) >= 48 && *(s + i) < 58)
		{
			res *= 10;
			res -= (*(s + i) - '0');
			flag = 1;
		}
		else if (flag == 1)
			break;
	}
	res *= minus;

	return (res);
}

/**
 * is_valid_number - Validation of ONLY a positive number in the string
 * @str: String
 *
 * Return: 1 Success
 * Otherwise, -1
 */
int is_valid_number(char *str)
{
	int i = 0;

	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			return (-1);
	}

	return (1);
}
