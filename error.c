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
	write(STDERR_FILENO, "not found\n", 10);

	return (0);
}
