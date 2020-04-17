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
			for (j = i; j >= 0; j--)
				free(binpath[j]);
			free(binpath)/*, free(input[0])*/; /*DOBLE MALLOC - POSIBLE CONFLICTO*/
			return (fullpath);
		}
		i++;
	}
	perror(fullpath);
	for (j = i; j >= 0; j--)
		free(binpath[j]);
	free(binpath), free(input);
	return (NULL);
}

/**
 * execute - execute the path
 * @input: string to execute + arguments
 *
 * Return: Always 0 success
 */
void execute(char **input)
{
	pid_t exechild;
	int status;

	exechild = fork();
	if (exechild < 0) /*Not create a child procces */
	{	/*PRINT VALUE FORK()*/
		/*free(input);*/
		exit(EXIT_FAILURE);
		/*return (exechild);*/
	}
	else if (exechild == 0)
	{
		if (execve(*input, input, environ) == -1)
		{
			perror(*input), free(input);
			/*return (execve(*input, input, environ));*/
			exit(EXIT_FAILURE);
		}
	}
	else /* Successful forks return positive process id's the parent */
		while (wait(&status) != exechild)
		{}
}
