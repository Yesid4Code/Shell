#include "headershell.h"

/**
 * main - Read, Search and execute the input
 * @argc: count arguments
 * @argv: array of arguments
 *
 * Return: Always 0 success
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	char **input; /* command typing by user */
	char **binpath; /* pointer to PATH*/
	size_t len = 0;
	ssize_t read;/*chars read by getline() */
	char *fullpath = NULL;
	struct stat fpath;/*struct to concatenate*/
	int i = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("#cisfun$ ");/*prompt */
		/*// READING PHASE \\ */
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		input = get_input(line); /*receive the command type by the user*/
		/*// SEARCHING PATH PHASE \\ */
		if (line[0] != '/')
		{
			binpath = get_path();
			if (!binpath)
				free(binpath), free(input), exit(EXIT_FAILURE);
			i = 0;
			while (binpath[i] != NULL)
			{	/*concatenate the strings*/
				fullpath = strdup(strcat(binpath[i], input[0]));
				/*exists or can exe?*/
				if ((stat(fullpath, &fpath) == 0))
				{
					input[0] = fullpath;
					break;
				}
				i++;
			}
			execute(input); /*// EXECUTE PHASE \\ */
		}
		else
			execute(input);
	}
	free(input), free(binpath), free(fullpath);
	return (0);
}
