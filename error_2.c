#include "header.h"

/**
 * help_not_found - prints the error output of a command
 * @programm: name of the program
 * @ar: incorrect command inserted
 *
 * Return: 0 on success
 */
int help_not_found(char *programm, char **ar)
{
	char msg[] = "no help topics match";
	char msg_2[] = "Try \'help help\' or 'man -k";
	char msg_3[] = "or \'info";

	write(STDERR_FILENO, programm, _strlen(programm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ar[0], _strlen(ar[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, &msg, _strlen(msg));
	write(STDERR_FILENO, " \'", 2);
	write(STDERR_FILENO, ar[1], _strlen(ar[1]));
	write(STDERR_FILENO, "\'. ", 3);
	write(STDERR_FILENO, &msg_2, _strlen(msg_2));
	write(STDERR_FILENO, " ", 1);
	write(STDERR_FILENO, ar[1], _strlen(ar[1]));
	write(STDERR_FILENO, "\' ", 2);
	write(STDERR_FILENO, &msg_3, _strlen(msg_3));
	write(STDERR_FILENO, " ", 1);
	write(STDERR_FILENO, ar[1], _strlen(ar[1]));
	write(STDERR_FILENO, "\'.", 2);
	write(STDERR_FILENO, "\n", 1);

	return (0);
}
