#include "header.h"

/**
 * compare_builtins_2 - desc
 * @ar: ...
 * @av: ...
 * @cnt: ...
 * @status: ...
 *
 * Return: 1 (Find a success compare)
 * -1 for error message printed,
 * Otherwise, 0
 */
int compare_builtins_2(char **ar, char **av, int cnt, int *status)
{
	int r_cd;

	r_cd = write_cd(ar, av, cnt);

	if (r_cd == -1)
	{
		*status = 2;
		return (-1);
	}
	else if (r_cd == 1)
	{
		*status = 0;
		return (1);
	}

	return (0);
}
