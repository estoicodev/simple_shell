#include "header.h"

/**
 * fprintenv - Prints the current environment
 * @env: Environment variable
 *
 * Return: void
 */
void fprintenv(char **env)
{
	int i;

	if (env)
		for (i = 0; *(env + i); i++)
			_puts(*(env + i));
}
/**
 * _setenv - If exists modify an environment variable.
 * If not, set a new environment variable
 * @ar: The array to use the function
 * Format
 * ar[0] = setenv
 * ar[1] = Variable
 * ar[2] = Content of the variable
 *
 * Return: 1 Success
 * 0, Don't do nothing
 * -1, Memory alloc error
 */
int _setenv(char **ar)
{
	int index;
	char *new_var;

	index = index_var_env(ar[1]);

	if (index == -2)
		return (0);
	else if (index == -1)
	{
		new_var = create_new_var_env(ar[1], ar[2]);
		if (new_var == NULL)
			return (-1);
		environ = new_environ_with_new_var(new_var);
		if (environ == NULL)
		{
			free(new_var);
			return (-1);
		}
	}
	else
		*(environ + index) = create_new_var_env(ar[1], ar[2]);

	return (1);
}

/**
 * _unsetenv - Remove an environment variable
 * @ar: The array to use the function
 * Format
 * ar[0] = unsetenv
 * ar[1] = Variable
 *
 * Return: 1 Success
 * -1, If not exist variable
 */
int _unsetenv(char **ar)
{
	int index;

	index = index_var_env(ar[1]);

	if (index == -1)
		return (-1);

	return (1);
}
