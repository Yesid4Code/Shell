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
		argstr[i] = malloc(sizeof(char) * strlen(tokens) + 1);/*allocate each string*/
		if (!argstr[i])
			return (NULL);
		argstr[i] = tokens;
		if (!strcmp("exit", tokens))/* verified if first tokens == "exit" */
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
 * get_path - search path to execute
 * @env: environ variables
 * Return: Always 0 success
 */
char **get_path(char **env)
{
	/*search path */
	char *path_token1; /* path before =, environ*/
	char *path_token2; /* path after =, environ*/
	char *bin_path = NULL; /* Bin path of the executable */
	char **argpath = NULL; /* array of bin paths to return */
	char *limpath[2] = {"=:"};
	int i;

	i = 0;
	while (env[i])
	{
		path_token1 = strtok(env[i], limpath[0]);
		path_token2 = strtok(NULL, limpath[0]);
		if (strcmp(path_token1, "PATH") == 0)
			break;/*path_token2 returns*/
		i++;
	}
	printf("%s\n", path_token2);

	/*bin_path = strtok(path_token2, limpath[0]);*/
	argpath = malloc(sizeof(char **));
	if (!argpath)
		return (NULL);
	i = 0;
	/* Falta concatenar PATH con comando ingresado */
	while (bin_path != NULL)/*token each PATH*/
	{
		argpath[i] = malloc(sizeof(char) * strlen(bin_path) + 1);/*allocate each path*/
                if (!argpath[i])
                        return (NULL);
		argpath[i] = bin_path;
		bin_path = strtok(NULL, limpath[1]);
		printf(" - %s\n", argpath[i - 1]);
		i++;
	}
	argpath[i] = NULL;
	return (argpath);
}
