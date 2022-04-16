#include "header.h"

/**
 * new_environ_with_new_var - Search the environment variable
 * @new_var: Environment variable
 *
 * Return: Line number of the environment variable
 * -1 - If doesn't exist
 */
char **new_environ_with_new_var(char *new_var)
{
	int size, new_size, aux_size, i;
	char *aux, **new_environ;

	if (environ)
		for (size = 0; *(environ + size); size++)
			;

	new_size = size + 1;
	new_environ = _calloc(new_size + 1, sizeof(char *));
	if (new_environ == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		aux_size = _strlen(*(environ + i));
		aux = _calloc(aux_size + 1, sizeof(char));
		if (aux == NULL)
			free_ar(new_environ);

		_strcpy(aux, *(environ + i));
		*(new_environ + i) = aux;
	}

	/* Add the new var */
	*(new_environ + i) = new_var;

	return (new_environ);
}

/**
 * index_var_env - Search the environment variable
 * @var_env: Environment variable
 *
 * Return: The index of the environment variable
 * -1 - If doesn't exist the environment variable
 * -2 - If environ is empty;
 */
int index_var_env(char *var_env)
{
	int i, size_var;

	if (!var_env)
		return (-2);

	size_var = _strlen(var_env);

	for (i = 0; *(environ + i); i++)
	{
		if (_strncmp(*(environ + i), var_env, size_var) == 0)
			return (i);
	}

	return (-1);
}

/**
 * getenv_var - Get a pointer to the environment variable
 * @var_env: Environment variable
 *
 * Return: Pointer to the complete line of the environment variable
 * Otherwise NULL
 */
char *getenv_var(char *var_env)
{
	int i, size_var;

	if (!var_env)
		return (NULL);

	size_var = _strlen(var_env);

	for (i = 0; *(environ + i); i++)
	{
		if (_strncmp(*(environ + i), var_env, size_var) == 0)
			return (*(environ + i));
	}

	return (NULL);
}

/**
 * create_new_var_env - get list of the path(s) of environment variable
 * @var_env: Environment variable
 * @var_content: Content of the variable
 *
 * Return: New string with the content of the environment variable
 * format -> VARIABLE=content
 * Otherwise NULL
 */
char *create_new_var_env(char *var_env, char *var_content)
{
	char separator[] = "=";
	int size;
	char *new_env;

	if (var_env == NULL || var_content == NULL)
		return (NULL);

	size = _strlen(var_env) + _strlen(separator) + _strlen(var_content);

	new_env = _calloc(size + 1, sizeof(char));

	if (new_env == NULL)
		return (NULL);

	_strcpy(new_env, var_env);
	_strcat(new_env, separator);
	_strcat(new_env, var_content);

	return (new_env);
}
