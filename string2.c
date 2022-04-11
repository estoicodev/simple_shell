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

/**
 * _itoa - integer to ascii
 * @num: num
 * @base: base
 *
 * Return: char
 * Reference: https://gist.github.com/narnat/95733cd0ad7bfac0d90697292914c407
 **/
char *_itoa(int num, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do      {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
