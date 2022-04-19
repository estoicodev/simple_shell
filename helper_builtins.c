#include "header.h"

/**
 * index_var_env - Search the environment variable
 * @var_env: Environment variable
 *
 * Return: The index of the environment variable
 * -1 - If an error occurs:
 * If the environment variable doesn't exist
 * If the environ is empty
 * If the var_env is NULL
 */
int index_var_env(char *var_env)
{
	int i, size_var;

	if (*(environ) == NULL)
		return (-1);

	if (var_env == NULL)
		return (-1);

	size_var = _strlen(var_env);

	for (i = 0; *(environ + i); i++)
	{
		if (_strncmp(*(environ + i), var_env, size_var) == 0)
			return (i);
	}

	return (-1);
}

/**
 * _getenv - Get a pointer to the environment variable
 * @var_env: Environment variable
 *
 * Return: Pointer to the complete line of the environment variable
 * Otherwise NULL
 */
char *_getenv(char *var_env)
{
	int i, size_var;
	char *env;

	if (!var_env || !*(environ) || !environ)
		return (NULL);

	size_var = _strlen(var_env);

	for (i = 0; *(environ + i); i++)
	{
		if (_strncmp(*(environ + i), var_env, size_var) == 0)
		{
			env = *(environ + i);
			if (*(env + size_var) == '=')
			{
				return (*(environ + i));
			}
		}
	}

	return (NULL);
}

/**
 * getenv_content - Get a pointer to the environment variable
 * @var_env: Environment variable
 * @line_env: Complete line of environment variable
 * Format: VARIABLE=content
 *
 * Return: Pointer to the content of the environment variable
 * Otherwise NULL
 */
char *getenv_content(char *var_env, char *line_env)
{
	int size_var;

	if (!var_env || !line_env)
		return (NULL);

	size_var = _strlen(var_env);

	if (*(line_env + size_var) == '=')
		return (line_env + size_var + 1);

	return (NULL);
}

/**
 * read_textfile - desc
 * @filename: ...
 * @letters: ...
 *
 * Return: ...
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, file_len, write_len;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	file_len = read(fd, buffer, letters);
	if (file_len == -1)
	{
		free(buffer);
		return (0);
	}

	write_len = write(STDOUT_FILENO, buffer, file_len);

	if (write_len != file_len)
	{
		free(buffer);
		return (0);
	}

	close(fd);

	free(buffer);

	return (file_len);
}
