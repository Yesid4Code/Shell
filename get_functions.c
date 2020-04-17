#include "headershell.h"

/**
 * get_input - get each argument typed for the user
 *
 * Return: Always 0 success
 */
char **get_input()
{
	char **argstr = NULL, *tokens = NULL, *limstr[4] = {" \t\n\r"};
	char *line = NULL;
	size_t len = 0;
	ssize_t read; /*count chars read by getline() */
	int i = 0;
	unsigned int sizepptr = 0; /* number of strings typed */

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	read = getline(&line, &len, stdin);
	if (read == EOF || !_strncmp(line, "exit\n", 4)) /* ||READING PHASE|| */
	{
		free(line);
		if ((read == EOF) && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	sizepptr = countstrings(line), argstr = (char **)malloc(sizeof(char *) * sizepptr);
	if (!argstr || (sizepptr == 0))
	{
		free(argstr), free(line);
		return (NULL);
	}
	tokens = strtok(line, *limstr); /* Tokenization the line typed*/
	while (tokens != NULL) /* Token each string */
	{
		argstr[i] = (char *)malloc(sizeof(char) * _strlen(tokens) + 1);/*+1?*/
		if (!argstr[i]) /* Allocate each string in argstr[i] */
		{
			freepptr(argstr), free(line);
			return (NULL);
		}
		argstr[i] = tokens;
		printf("%s\n", argstr[i]);
		tokens = strtok(NULL, *limstr);
		i++;
	}
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
	{	/*return pointer to subdir*/
		if (_strncmp(environ[i], envar, _strlen(envar)) == 0)
			return (environ[i] + _strlen(envar) + 1);
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
	int i = 0;
	unsigned int sizepptr = 0; /* number of subdirectories */

	path = _strdup(get_environ("PATH")); /* pointer to the copy of path*/
	if (!path)
		return (NULL);
	sizepptr = countstrings(path);
	argpath = (char **)malloc(sizeof(char *) * sizepptr/* + 1*/);
	if (argpath == NULL)
	{
		free(path);
		return (NULL);
	}
	path_token = _strdup(strtok(path, limpath[0]));
	if (path_token == NULL)
	{
		free(argpath), free(path);
		return (NULL);
	}
	while (path_token != NULL) /* Tokenization each subdirectories */
	{
		argpath[i] = str_concat(path_token, "/");
		if (!argpath[i])
		{
			freepptr(argpath), free(path_token), free(path);
			return (NULL);
		}
		path_token = strtok(NULL, *limpath);
		i++;
	}
	free(path_token), free(path); /*free paths var*/
	return (argpath);
}
