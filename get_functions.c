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
	char **argv;
	char *tokens = NULL;/* containt each string typing */
	char *limstr[1] = {" \t\n\r"};/* string delimited */
	int i = 0;

	tokens = strtok(line, *limstr);
	i = 0;
	while (tokens != NULL && i < 50)/*token each string*/
	{
		argv[i] = tokens;
		if (!strcmp("exit", argv[0]))
			exit(1);
		tokens = strtok(NULL, *limstr);
		i++;
		printf("%s\n", argv[0]);
	}
	argv[i] = NULL;
	return (argv);
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
	char **argv = NULL; /*array of bin paths */
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

	bin_path = strtok(path_token2, limpath[0]);
	printf("%s", bin_path);
	i = 0;
	/* concatenar PATH con comando ingresado */
	while (bin_path != NULL)/*token each PATH*/
	{
		argv[i] = bin_path;
		bin_path = strtok(NULL, limpath[1]);
		i++;
	}
	printf(" - %s\n", argv[i - 1]);
	argv[i] = NULL;
	return (argv);
}
