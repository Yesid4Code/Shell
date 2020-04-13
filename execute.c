#include "headershell.h"

/**
 * execute - execute the path
 * @binpath: string to execute + arguments
 *
 * Return: Always 0 success
 */
void execute(char **binpath)
{
	pid_t exechild;
	int status;

	exechild = fork();
	if (exechild < 0) /*create a child procces? */
		exit(EXIT_FAILURE);
	else if (exechild == 0)
	{
		if (execve(*binpath, binpath, NULL) == -1)
			perror(*binpath), free(binpath);
	}
	else
		while (wait(&status) != exechild)
		{}
}
