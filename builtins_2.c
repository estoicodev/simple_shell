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
 * compare_dollar - Compare the cases of dollar symbol
 * @ar: Array of tokens
 * @status: Return status
 *
 * Return: void
 */
int compare_dollar(char **ar, int status)
{
	int i, j, res;
	char *tmp;

	if (ar == NULL && *(ar) == NULL)
		return (0);

	for (i = 0; *(ar + i); i++)
	{
		res = write_dollar_symbol(*(ar + i), status);
		if (res == 0)
			continue;
		else if (res == -1)
		{
			perror("An error of allocation memory occurs");
			return (-1);
		}
		else if (res == -2 && i != 0)
		{
			tmp = *(ar + i);
			for (j = 0; *(tmp + i); j++)
				*(tmp + i) = '\0';
			_strcpy(tmp, "");
		}
	}

	return (0);
}

/**
 * write_dollar_symbol - Validate the cases with dollar symbol
 * @token: A token
 * @status: Return status
 *
 * Return: void
 */
int write_dollar_symbol(char *token, int status)
{
	char *num, *content_env;
	pid_t pid;
	int i;

	if (token == NULL)
		return (-1);

	if (_strlen(token) == 1 || *(token + 0) != '$')
		return (0);

	if (*(token + 1) == '?')
	{
		num = _itoa(status, 10);
		for (i = 0; *(token + i); i++)
			*(token + i) = '\0';
		_strcpy(token, num);
		return (1);
	}
	else if (*(token + 1) == '$')
	{
		pid = getpid();
		num = _itoa(pid, 10);
		for (i = 0; *(token + i); i++)
			*(token + i) = '\0';
		_strcpy(token, num);
		return (1);
	}

	if (index_var_env(token + 1) == -1)
		return (-2);

	content_env = find_var_env(token + 1);
	for (i = 0; *(token + i); i++)
		*(token + i) = '\0';
	_strcpy(token, content_env);

	return (0);
}

/**
 * find_var_env - Prints the current environment
 * @var_env: Environment variable
 *
 * Return: 1 Success
 * Otherwise, 0
 */
char *find_var_env(char *var_env)
{
	char *line_env, *content_env;

	if (!var_env)
		return (NULL);

	line_env = _getenv(var_env);
	if (!line_env)
		return (NULL);

	content_env = getenv_content(var_env, line_env);
	if (!content_env)
		return (NULL);

	return (content_env);
}
