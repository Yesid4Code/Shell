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

	argstr = malloc(sizeof(char **));
	if (!argstr)
		return (NULL);
	i = 0;
	while (tokens != NULL)/*token each string*/
	{
		/* Allocate each string in argstr[i]*/
		argstr[i] = malloc(sizeof(char) * strlen(tokens) + 1);
		if (!argstr[i])
			return (NULL);
		argstr[i] = tokens;
		if (!strcmp("exit", argstr[0]))/* verified if first tokens == "exit" */
		{
			free(argstr[i]);
			free(argstr);
			exit(1);
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
		if(strncmp(environ[i], envar, strlen(envar)) == 0)
			/*return pointer to subdir*/
			return (environ[i] + strlen(envar) + 1);
		i++;
	}
}

/**
 * get_path - search path to execute
 * @env: environ variables
 * Return: Always 0 success
 */
char **get_path(char **env)
{
	/*search path */
	char *path, **argpath = malloc(sizeof(char *) * 64);
	char *limpath[1] = {":"};
	int i = 0, j = 0;

	path = strdup(get_environ("PATH")); /* pointer to the copy of path*/
	path_token = strtok(path, limpath[0]);

	printf("Hola prueba PATH\n", path_token);
	while (path_token != NULL)
	{
		/* allocate each path*/
                argpath[i] = malloc(sizeof(char) * strlen(path_token) + 1);
                if (!argpath[i])
                {
                        for (j = 0; j <= i; j++)
                                free(argpath[j]);
                        free(argpath);
                        return (NULL);
                }
		argpath[i] = path_token;
		path_token = strtok(NULL, limpath[0]);
		i++;
	}
	printf("before add NULL\N");
	argpath[i] = NULL;
	return (argpath);
}
