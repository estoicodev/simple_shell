#include "header.h"
/**
 * _getenv - get list of the path(s) of environment variable
 * @env: Environment variable
 *
 * Return: New string of the path(s) of environment variable
 * Otherwise NULL
 */
char *_getenv(char *env)
{
	int i;
	char *envline = malloc(1024);
	char *envpath = malloc(1024);

	for (i = 0; *(environ + i); i++)
	{
		if (_strncmp(*(environ + i), env, _strlen(env)) == 0)
		{
			_strcpy(envline, *(environ + i));
			break;
		}
	}
	if (envline != NULL)
	{
		for (i = 0; i < (_strlen(env) + 1); i++)
			;
		_strcpy(envpath, envline + i);

		free(envline);
	}


	return (envpath);
}

/**
int main(void)
{
	char *env_line = _getenv("XDXD");

	if (env_line)
	{
		printf("%s\n", env_line);
		free(env_line);
	}
	else
		printf("Doesn't exist the env var\n");

	return (0);
}
*/

/**
 * get_PATHS - Get and tokenizes PATHS
 *
 * Return: New array of tokens of PATHS
 */
char **get_PATHS(void)
{
	int i = 0, size = 0;
	char **aux;
	char **paths;
	char *path = _getenv("PATH");
	char delim[] = ":";

	paths = tokenizer(path, delim);

	while (paths[i++])
	{
		size++;
		i++;
	}

	/* Concat each string with backslash at the end */
	aux = foreach_concat(paths, "/");

	free(path);
	free_ar(paths);

	return (aux);
}

/* Without get_PATHS (Todo OK) */
/**
int main(void)
{
	char **env;
	char *path = _getenv("PATH");
	char *delim = ":";
	env = split_string(path, delim);

	if (env)
	{
		print_ar(env);
		free(env);
	}
	if (path)
		free(path);

	return (0);
}
*/

/* With get_PATHS (contextERRORS) */
/**
int main(void)
{
	char **paths = get_PATHS();

	if (paths)
	{
		print_ar(paths);
		free_ar(paths);
	}

	return (0);
}
*/

char **foreach_concat(char **ar, char *src)
{
	char **new_ar;
	int size = 0, i = 0;

	for (size = 0; ar[size]; size++)
		;

	new_ar = _calloc(size + 1, sizeof(char *));
	if (new_ar == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		new_ar[i] = str_concat(ar[i], src);
	}

	return (new_ar);
}
/**
int main(void)
{
	char *paths[] = { "/bin", "/usr/bin", "/usr/games", "/sbin", NULL};
	char **new = foreach_concat(paths, "/");

	if (paths)
	{
		print_ar(paths);
	}
	if (new)
	{
		print_ar(new);
		free_ar(new);
	}

	return (0);
}
*/
