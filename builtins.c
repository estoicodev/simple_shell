#include "header.h"

/**
 * write_cd - Find if user enter 'cd' built-in
 * @ar: ...
 * @av: ...
 * @cnt: ...
 *
 * Return: 1 If cd Success
 * If not, 0
 * If an error occurs -1
 */
int write_cd(char **ar, char **av, int cnt)
{
	char *path, pwd[100], *old_pwd, var_oldpwd[] = "OLDPWD";
	size_t sz = 100;

	if (_strcmp(ar[0], "cd") == 0 && _strlen(ar[0]) == 2)
	{
		getcwd(pwd, sz);
		if (cmp_cd_only(ar[1]) == 1)
		{
			path = go_to_home_directory();
			if (path == NULL)
				return (-1);
			setenv(var_oldpwd, pwd, 1);
			return (1);
		}
		else if (cmp_cd_dash(ar[1]) == 1)
		{
			old_pwd = get_oldpwd();
			go_to_dir(old_pwd);
			setenv(var_oldpwd, pwd, 1);
			_puts(getcwd(pwd, sz));
			return (1);
		}
		if (go_to_dir(ar[1]) == -1)
		{
			error_cd(av[0], cnt, ar);
			return (-1);
		}
		else
		{
			setenv(var_oldpwd, pwd, 1);
			return (1);
		}
	}

	return (0);
}

/**
 * write_help - Find if user enter 'help' built-in
 * @ar: ...
 * @av: ...
 *
 * Return: 1 If help Success
 * If not, 0
 * If an error occurs -1
 */
int write_help(char **ar, char **av)
{
	ssize_t rd;

	if (_strcmp(ar[0], "help") == 0 && _strlen(ar[0]) == 4)
	{
		if (ar[1] == NULL)
		{
			rd = read_textfile("just_help", 4096);
			if (rd == 0)
				return (-1);
			return (1);
		}

		if (write_help_command(ar[1]) == 1)
		{
			rd = read_textfile(ar[1], 4096);
			if (rd == 0)
				return (-1);
			return (1);
		}
		else
		{
			help_not_found(av[0], ar);
			return (-1);
		}
	}

	return (0);
}

/**
 * write_exit - Find if user enter 'exit' to go out of the shell
 * @ar: ...
 * @status: ...
 *
 * Return: 0 If 'exit' don't printed
 * Otherwise, -1
 */
int write_exit(char **ar, int *status)
{
	int ex;

	if (_strcmp(ar[0], "exit") == 0 && _strlen(ar[0]) == 4)
	{
		if (ar[1] != NULL)
		{
			if (is_valid_number(ar[1]) == 1)
			{
				ex = _atoi(ar[1]);
				free_ar(ar);
				exit(ex);
			}
			else
				return (-1);
		}
		else
		{
			free_ar(ar);
			exit(*status);
		}
	}

	return (0);
}

/**
 * write_setenv - Find if user enter 'exit' to go out of the shell
 * @ar: ...
 * @av: ...
 * @cnt: ...
 * @status: ...
 *
 * Return: 1 If setenv is printed
 * If not, 0
 * If an error occurs -1
 */
int write_setenv(char **ar, char **av, int cnt, int *status)
{
	if (_strcmp(ar[0], "setenv") == 0 && _strlen(ar[0]) == 6)
	{
		if (ar[1] == NULL)
			return (1);

		if (ar[2] == NULL)
			return (1);

		if (ar[3] != NULL || setenv(ar[1], ar[2], 1) == -1)
		{
			*status = 2;
			error_set_unset_env(av[0], cnt, ar);
			return (-1);
		}

		return (1);
	}

	return (0);
}

/**
 * write_unsetenv - Find if user enter 'exit' to go out of the shell
 * @ar: ...
 * @av: ...
 * @cnt: ...
 * @status: ...
 *
 * Return: 1 If setenv is printed with all arguments
 * If not, 0
 * If an error occurs -1
 */
int write_unsetenv(char **ar, char **av, int cnt, int *status)
{
	if (_strcmp(ar[0], "unsetenv") == 0 && _strlen(ar[0]) == 8)
	{
		if (ar[1] == NULL)
			return (1);

		if (ar[2] != NULL || unsetenv(ar[1]) == -1)
		{
			*status = 2;
			error_set_unset_env(av[0], cnt, ar);
			return (-1);
		}

		return (1);
	}

	return (0);
}
