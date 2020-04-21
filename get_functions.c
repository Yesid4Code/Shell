#include "headershell.h"

/**
 * printpromt - prints prompt and eval other option
 *
 * Return: Always 0 success
 */
char *printpromt()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read; /*count chars read by getline() */

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
	return (line);
}

/**
 * get_input - get each argument typed for the user
 * @line: string enter for the user
 * Return: Always 0 success
 */
char **get_input(char *line)
{
	char **argline = NULL, *tokens = NULL, *limstr[4] = {" \a\t\n\r"};
	unsigned int sizepptr = 0; /* number of strings typed */
	int i = 0;

	sizepptr = countstrings(line);/*length string typed*/
	argline = _calloc((sizepptr + 2), sizeof(char *));
	if (!argline || !sizepptr)
	{
		free(line);
		return (NULL);
	}
	tokens = strtok(line, *limstr); /* Tokenization the line typed*/
	while (tokens != NULL) /* Token each string */
	{
		argline[i] = malloc(sizeof(char) * _strlen(tokens) + 2);
		if (!argline[i]) /* Allocate each string in argstr[i] */
		{
			freepptr(argline), free(line);
			return (NULL);
		}
		_copy(argline[i], tokens);
		tokens = strtok(NULL, *limstr);
		i++;
	}
	argline[i] = NULL;
	free(line);
	return (argline);
}

/**
 * get_path - find the command path to will be execute
 * @input: command to search the path
 *
 * Return: Always 0 success
 */
char *get_path(char *input)
{
	int i = 0;
	char *delim[2] = {"=:"};
	char *copy_env = NULL, *tok = NULL, *fullpath = NULL;
	struct stat fpath;

	while (/*environ && */environ[i]) /*environ is a pointer function??*/
	{
		copy_env = _strdup(environ[i]); /* ENVIRON */
		if (copy_env == NULL)
			return (NULL);
		tok = strtok(copy_env, *delim); /* Tokenization of copy_env */
		/* reserve memory to concatenate tok+/+argline[0] */
		while (tok != NULL)
		{
			fullpath = malloc(sizeof(char *) *
					  (_strlen(tok) + _strlen(input) + 1));
			_memset(fullpath, 0, _strlen(fullpath));
			if (fullpath == NULL)
			{
				free(copy_env);
				return (NULL);
			}
			/* Getting the complete path */
			_copy(fullpath, tok);
			str_concat(fullpath, "/");
			str_concat(fullpath, input);
			if (stat(fullpath, &fpath) == 0)
			{
				free(copy_env);
				return (fullpath);
			}
			/*_memset(fullpath, 0, _strlen(fullpath));*/
			free(fullpath);
			tok = strtok(NULL, *delim);
		}
		free(copy_env);
		i++;
	}
	return (NULL);
}
