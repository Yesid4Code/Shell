#include "headershell.h"

/**
 * get_input - get input typing for the user
 * @line: string type
 * @read: value from get_line function, 0 Ok, -1 failure
 *
 * Return: Always 0 success
 */
char **get_input(char *line)
{
	char **argstr;/* pointer to return */
	char *tokens = NULL;/* containt each string typing */
	char *limstr[1] = {" \t\n\r"};/* string delimited */
	int i = 0;/*, j;*/
	/*char *line = _strdup(li);*/

	/*printf("%s", line);*/
	if (*line == '\n')
		return (NULL);
	tokens = strtok(line, *limstr);
	/* Verified Ctrl+D was type or if first token == "exit"*/
	/** if (read == EOF)
	{
		for (j = i; j >= 0; j--)
			free(argstr[j]);
		free(argstr);
		if (read == EOF)
			write(STDOUT_FILENO, "\n", 1);*/
		/*exit(EXIT_SUCCESS); } */

	argstr = malloc(sizeof(char *) * 64);
	if (!argstr)
		return (NULL);

	while (tokens != NULL)/*token each string*/
	{
		/* Allocate each string in argstr[i]*/
		argstr[i] = malloc(sizeof(char) * strlen(tokens) + 1);
		if (!argstr[i])
		{
			free(argstr[i]);
			free(argstr);
			return (NULL);
		}
		argstr[i] = tokens;
		tokens = strtok(NULL, *limstr);
		i++;
	}
	argstr[i] = NULL;
	/*free(line);*/
	return (argstr);
}

/**
 * get_environ - search environ
 * @envar: environ
 * Return: Always 0 success
 */
char *get_environ(char *envar)
{
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], envar, strlen(envar)) == 0)
			/*return pointer to subdir*/
			return (environ[i] + strlen(envar) + 1);
		i++;
	}
	return (NULL);
}

/**
 * get_path - get subdirectories
 *
 *
 * Return: Always 0 success
 */
char **get_path()
{
	/* search path */
	/*store 7 positions*/
	char *path = NULL, **argpath = malloc(sizeof(char *) * 64);
	char *path_token = NULL;
	char *limpath[1] = {":"};
	int i = 0, j = 0;

	path = _strdup(get_environ("PATH")); /* pointer to the copy of path*/
	if (!path)
	{
		free(path), free(argpath);
		return (NULL);
	}
	path_token = strtok(path, limpath[0]);/*duplicate path*/

	while (path_token != NULL && i < 8)/*My hardcore to work excellent*/
	{
		argpath[i] = _strdup(path_token);
		if (!argpath[i])
		{
			for (j = i; j >= 0; j--)
				free(argpath[j]);
			free(argpath);
			return (NULL);
		}
		strcat(argpath[i], "/"), path_token = strtok(NULL, ":");
		i++;
	}
	argpath[i] = NULL, free(path_token), free(path); /*free paths var*/
	return (argpath);
}
