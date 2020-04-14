#include "headershell.h"

/* SEARCHING PATH PHASE*/
/**
 * pathtoexecute - search directory of a command
 * @argpath: receive the environ path.
 *
 * Return
 */
char *pathtoexecute(char **input)
{
	char **binpath;
	char *fullpath = NULL;
	int i = 0;
	struct stat fpath;

	binpath = get_path();
	if (!binpath)
	{
		free(binpath), free(input);/*exit(EXIT_FAILURE);*/
		return (NULL);
	}
	while (binpath[i] != NULL)
	{       /*concatenate the strings*/
		fullpath = _strdup(strcat(binpath[i], input[0]));
		/*exists or can exe?*/
		if ((stat(fullpath, &fpath) == 0))
		{
			free(binpath), free(input);
			return (fullpath);
		}
		i++;
	}
	free(fullpath), free(binpath), free(input);
	return (NULL);
}

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
		exit(EXIT_FAILURE); /*return (NULL);*/
	else if (exechild == 0)
	{
		if (execve(*binpath, binpath, environ) == -1)
		{
			perror(*binpath), free(binpath);
		}
	}
	else
		while (wait(&status) != exechild)
		{}
}
