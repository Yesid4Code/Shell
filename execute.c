#include "headershell.h"

/**
 * pathtoexecute - search directory of a command
 * @input: receive the environ path.
 *
 * Return: path to command, ex: /bin/ls
 */
char *pathtoexecute(char **input)/* SEARCHING PATH PHASE*/
{
	char **binpath = NULL;
	char *fullpath = NULL;
	int i = 0, j = 0;
	struct stat fpath;

	binpath = get_path();
	if (!binpath)
		return (NULL);
	while (binpath && binpath[i] != NULL)/* exists */
	{/*concatenate the strings*/
		fullpath = str_concat(binpath[i], input[0]);
		/*exists or can exe?*/
		if ((stat(fullpath, &fpath) == 0))
		{
			freepptr(binpath)/*, free(input[0])*/; /*DOBLE MALLOC - POSIBLE CONFLICTO*/
			return (fullpath);
		}
		i++;
	}
	perror(*input);/*Print error message */
	freepptr(binpath); /*DON'T FREE INPUT*/
	return (NULL);
}

/**
 * execute - execute the path
 * @input: string to execute + arguments
 * @cmd: command path
 * @env: array of environment variables
 * Return: Always 0 success
 */
int execute(char *cmd, char **input, char **env)
{
	pid_t exechild;
	int status;

	exechild = fork();
	if (exechild < 0) /*Not create a child procces */
	{	/*PRINT VALUE FORK()*/
		/*free(input);*/
		return (exechild); /* exit(EXIT_FAILURE); */
	}
	else if (exechild == 0)
	{
		return (execve(cmd, input, env));
	}
	else /* Successful forks return positive process id's the parent */
		while (wait(&status) != exechild)
		{}
	return (0);
}
