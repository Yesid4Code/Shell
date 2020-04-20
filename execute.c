#include "headershell.h"

/**
 * pathtoexecute - search directory of a command
 * @input: receive the environ path.
 *
 * Return: path to command, ex: /bin/ls
 *
*char *pathtoexecute(char **input) SEARCHING PATH PHASE
*{
*	char **binpath = NULL;
*	char *fullpath = NULL;
*	int i = 0;
*	struct stat fpath;
*
*	binpath = get_path();
*	if (!binpath)
*		return (NULL);
*	while (binpath && binpath[i] != NULL) exists
*	{concatenate the strings
*		fullpath = str_concat(binpath[i], input[0]);
*		exists or can exe?
*		if ((stat(fullpath, &fpath) == 0))
*		{
*			freepptr(binpath), free(input[0]) MALLOC
*			return (fullpath);
*		}
*		i++;
*	}
*	perror(*input);Print error message
*	freepptr(binpath); ON'T FREE INPUT
*	return (NULL);
*}
*/

/**
 * execute - execute the path.
 * @input: string to execute + arguments.
 * @cmd: command path.
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
			/*free(input);*/
			/*sprintf(err_msg, "%s: %d: %s: not found\n",*/
			/*argv[0], countexec, input[0]);*/
			/*write(2, err_msg, _strlen(err_msg));*/
			exit(2);
			/*return (exechild);  exit(EXIT_FAILURE); */
		}
		else if (exechild == 0)
		{
			if (execve(fullpath, input, env) == -1)
			{
				sprintf(error, "%s: %d: %s: not found\n",
					argv, countexec, input[0]);
				write(2, error, _strlen(error));
			}
		}
		else /* Successful forks return positive process id's the parent */
			while (wait(&status) != exechild)
			{}
	}/* command not found. */
	sprintf(error, "%s: %d: %s: not found\n",
		argv, countexec, input[0]);
	write(2, error, _strlen(error));
	/* free? */
	return (-1);/* return (127) ?? */
}
