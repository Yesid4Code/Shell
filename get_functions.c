#include "headershell.h"
#include <stdio.h>
/**
 * get_input - get input typing for the user
 * @line: string type
 *
 *
 * Return: Always 0 success
 */
char **get_input(char *line)
{
	char **argstr;/* pointer to return */
	char *tokens = NULL;/* containt each string typing */
	char *limstr[1] = {" \t\n\r"};/* string delimited */
	int i = 0;

	tokens = strtok(line, *limstr);

	argstr = malloc(sizeof(char *));
	if (!argstr)
		return (NULL);
	i = 0;
	while (tokens != NULL)/*token each string*/
	{
		/* Allocate each string in argstr[i]*/
		argstr[i] = malloc(sizeof(char) * strlen(tokens) + 1);
		if (!argstr[i])
		{
			free(argstr[i]), free(argstr);
			return (NULL);
		}
		argstr[i] = tokens;
		if (!strcmp("exit", argstr[0]))/* verified if first tokens == "exit" */
		{
			free(argstr[i]), free(argstr);
			exit(EXIT_SUCCESS);
		}
		tokens = strtok(NULL, *limstr);
		printf("%s\n", argstr[i]);/* prueba de funcionamiento */
		i++;
	}
	argstr[i] = NULL;
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
	char *path, **argpath = malloc(sizeof(char *) * 64);/*store 7 positions*/
	char *path_token;
	char *limpath[1] = {":"};
	int i = 0, j = 0;

	path = strdup(get_environ("PATH")); /* pointer to the copy of path*/
	path_token = strdup(strtok(path, limpath[0]));/*duplicate path*/

	while (path_token != NULL && i < 7)/*My hardcore to work excellent*/
	{
		/* allocate each path*/
		argpath[i] = malloc(sizeof(char) * strlen(path_token) + 2);/* "/\0" */
		if (!argpath[i])
		{
			for (j = i; j >= 0; j--)
				free(argpath[j]);
			free(argpath), free(path_token), free(path);
			return (NULL);
		}
		printf("%s :\n", path_token);
		argpath[i] = strdup(strcat(path_token, "/"));
		path_token = strdup(strtok(NULL, limpath[0]));
		i++;
	}
	printf("argpath[%d]= %s\n", i, argpath[i]);
	argpath[i] = NULL, free(path_token), free(path);/*free paths var*/
	return (argpath);
}
/**
 * pathtoexecute - concate
 *
 *
 * Return: Always 0 success
 */
char *pathtoexecute(char **argpath)
{
	(void);
}
