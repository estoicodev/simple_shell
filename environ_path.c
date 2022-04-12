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
	char *envline = NULL;
	char *envpath = NULL;

	for (i = 0; *(environ + i); i++)
	{
		if (_strncmp(*(environ + i), env, _strlen(env)) == 0)
		{
			envline = str_concat(envline, *(environ + i));
			break;
		}
	}
	if (envline != NULL)
	{
		for (i = 0; i < (_strlen(env) + 1); i++)
			;
		envpath = str_concat(envpath, envline + i);

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
	int i = 0, size;
	char *aux;
	char **env;
	char *path = _getenv("PATH");
	char *delim = ":";

	env = split_string(path, delim);
	if (!env)
	{
		free(path);
		return (NULL);
	}

	/* Add backslash at the end to each path*/
	for (i = 0; env[i] != NULL; i++)
	{
		size = _strlen(env[i]);
		aux = malloc((size + 2) * sizeof(char));
		_strcpy(aux, env[i]);
		_strcat(aux, "/");
		env[i] = NULL;
		env[i] = malloc((size + 2) * sizeof(char));
		env[i] = aux;
		aux = NULL;
	}

	free(path);

	return (env);
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
	char **env = get_PATHS();

	if (env)
	{
		print_ar(env);
		free(env);
	}

	return (0);
}
*/
