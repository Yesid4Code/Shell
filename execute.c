#include "headershell.h"

/**
 * execute - execute the command path
 * @argv: array of arguments generated from the execution
 * @fullpath: command path
 * @input: string to execute + arguments.
 * @env: array of environment variables.
 * @countexec: number of times program executed.
 *
 * Return: -1 if error.
 */
int execute(char *argv, char *fullpath,
	    char **input, char **env, unsigned int countexec)
{
	int status;
	char error[100];
	pid_t exechild;
	struct stat fpath;

	if (stat(fullpath, &fpath) == 0)
	{
		exechild = fork();
		if (exechild < 0) /*Not create a child procces */
		{	/*PRINT VALUE FORK()*/
			freepptr(input); /*add frees*/
			return (127);
		}
		else if (exechild == 0)
		{
			if (execve(fullpath, input, env) == -1)
			{
				sprintf(error, "%s: %d: %s: not found\n",
					argv, countexec, input[0]);
				write(2, error, _strlen(error));
				freepptr(input);
				exit(127);
			}
		}
		else /* Successful forks return positive process id's the parent */
			while (wait(&status) != exechild)
			{}
	} /* command not found. */
	else /* add this else */
	{
		sprintf(error, "%s: %d: %s: not found\n", argv, countexec, input[0]);
		write(2, error, _strlen(error));
		freepptr(input);
		return (127);
	} /*add this return*/
	return (0);
}
