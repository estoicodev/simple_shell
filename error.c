#include "header.h"

/**
 * print_error - prints the error output of a command
 * @programm: name of the program
 * @count: number of prompt
 * @command: incorrect command inserted
 * Return: 0 on success
 */
int print_error(char *programm, int count, char *command)
{
	char *number = _itoa(count, 10);

	write(STDERR_FILENO, programm, _strlen(programm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, number, _strlen(number));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 2);
	perror("");

	return (0);
}

int ext_err(char *programm, int count, char **ar)
{
	char *number = _itoa(count, 10);
	char msg[] = "Illegal number";

	write(STDERR_FILENO, programm, _strlen(programm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, number, _strlen(number));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ar[0], _strlen(ar[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, &msg, _strlen(msg));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ar[1], _strlen(ar[1]));
	write(STDERR_FILENO, "\n", 1);

	return (0);
}
