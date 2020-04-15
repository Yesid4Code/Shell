#include "headershell.h"

/**
 * get_input - get input typing for the user
 * @line: string type
 *
 * Return: Always 0 success
 */
char **get_input()
{
	char **argstr = NULL, *tokens = NULL, *limstr[4] = {" \t\n\r"};
	char *line = NULL;
	size_t len = 0;
	ssize_t read; /*chars read by getline() */
	int i = 0, j;
	unsigned int sizepptr = 0; /* number of strings typed */

	/* ||READING PHASE|| */
	read = getline(&line, &len, stdin);
	if (read == EOF || !strncmp(line, "exit\n", 4))
	{
		if (read == EOF)
			write(STDOUT_FILENO, "\n", 1);
		free(line), exit(EXIT_SUCCESS);
	}
	sizepptr = countstrings(line), argstr = malloc(sizeof(char *) * sizepptr);
	if (!argstr || (sizepptr == 0))
	{
		free(argstr); free(line);
		return (NULL);
	}
	tokens = strtok(line, *limstr); /* Tokenization the line typed*/
	while (tokens != NULL) /* Token each string */
	{
		/* Allocate each string in argstr[i] */
		argstr[i] = malloc(sizeof(char) * strlen(tokens) + 1);/*+1?*/
		if (!argstr[i])
		{
			for (j = i; j >= 0; j--) /* freezing argstr*/
				free(argstr[i]);
			free(argstr);
			return (NULL);
		}
		argstr[i] = tokens;
		tokens = strtok(NULL, *limstr);
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
 * Return: Always 0 success
 */
char **get_path()
{
	char *path = NULL, **argpath = NULL;
	char *path_token = NULL;
	char *limpath[1] = {":"};
	int i = 0, j = 0;
	unsigned int sizepptr = 0; /* number of subdirectories */

	path = _strdup(get_environ("PATH")); /* pointer to the copy of path*/
	if (!path)
		return (NULL);
	sizepptr = countstrings(path);
	argpath = malloc(sizeof(char *) * sizepptr);
	if (argpath == NULL)
	{
		free(path);
		return (NULL);
	}

	path_token = _strdup(strtok(path, limpath[0]));
	while (path_token != NULL) /* Tokenizatio each subdirectories */
	{
		argpath[i] = malloc(sizeof(char *) * strlen(path_token) + 1);
		if (!argpath[i])
		{
			for (j = i; j >= 0; j--)
				free(argpath[j]);
			free(argpath), free(path);
			return (NULL);
		}
		argpath[i] = _strdup(path_token), strcat(argpath[i], "/");
		path_token = strtok(NULL, *limpath);
		i++;
	}
	argpath[i] = NULL;
	free(path_token), free(path); /*free paths var*/
	return (argpath);
}
