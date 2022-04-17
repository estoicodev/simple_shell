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
