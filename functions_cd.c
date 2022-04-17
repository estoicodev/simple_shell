#include "header.h"

/**
 * go_to_dir - Find if user enter 'cd' built-in
 * @directory: ...
 *
 * Return: 1 If Success
 * Otherwise, 0
 */
int go_to_dir(char *directory)
{
	char pwd_path[] = "PWD";
	char str[100];
	size_t sz = 100;

	if (!directory)
		return (0);

	if (chdir(directory) == -1)
		return (-1);

	if (setenv(pwd_path, getcwd(str, sz), 1) == -1)
		return (-1);

	return (1);
}


/**
 * go_to_home_directory - Find if user enter 'cd' built-in
 *
 * Return: If Success, returns HOME directory
 * Otherwise, NULL
 */
char *go_to_home_directory(void)
{
	char home_path[] = "HOME";
	char pwd_path[] = "PWD";
	char *line_env, *content_env;

	line_env = _getenv(home_path);
	if (!line_env)
		return (NULL);

	content_env = getenv_content(home_path, line_env);
	if (!content_env)
		return (NULL);

	if (chdir(content_env) == -1)
		return (NULL);

	if (setenv(pwd_path, content_env, 1) == -1)
		return (NULL);

	return (content_env);
}

/**
 * cmp_cd_only - Find if user enter only 'cd'
 * @str: String to compare
 *
 * Return: 1, If Success
 * Otherwise, 0
 */
int cmp_cd_only(char *str)
{
	if (str == NULL)
		return (1);

	return (0);
}

/**
 * cmp_cd_dash - Find if user enter 'cd -'
 * @str: String to compare
 *
 * Return: 1, If Success
 * Otherwise, 0
 */
int cmp_cd_dash(char *str)
{
	if (_strcmp(str, "-") == 0 && _strlen(str) == 1)
		return (1);

	return (0);
}

/**
 * get_oldpwd - Get the content of the OLDPWD environment variable
 *
 * Return: If Success, returns the content of OLDPWD
 * Otherwise, NULL
 */
char *get_oldpwd(void)
{
	char *line_env, *content_env;

	line_env = _getenv("OLDPWD");
	if (!line_env)
		return (NULL);
	content_env = getenv_content("OLDPWD", line_env);
	if (!content_env)
		return (NULL);

	return (content_env);
}
