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
		printf("#cisfun$> ");/*prompt */

		/*// READING PHASE \\ */
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		input = get_input(line); /*receive the command type by the user*/

		/*// SEARCHING PATH PHASE \\ */
		/*-----------------*/
		if (line[0] != '/')
		{
			binpath = malloc(sizeof(char *) * 64);
			if (!binpath)
				exit(EXIT_FAILURE);
			binpath = get_path();

			for (i = 0; binpath[i] != NULL; i++)/*prueba de salida*/
				printf("binpath = %s\n", binpath[i]);

			i = 0;
			while (binpath[i] != NULL)
			{	/*concatenate the strings*/
				fullpath = strdup(strcat(binpath[i], input[0]));
				/*exists or can exe?*/
				printf("%s\n", fullpath);/* prueba */
				if ((stat(fullpath, &fpath) == 0))/* path valid? */
				{
					input[0] = fullpath;
					break;
				}
				printf("Value stat --> %d\n", stat(fullpath, &fpath));/*prueba*/
				i++;
				printf("binpath = %s\n", binpath[i]);/*prueba*/
			}
			execute(input); /*// EXECUTE PHASE \\ */
		}
		else
			execute(input);

	}
	free(line);
	free(input);
	free(binpath);
	return (0);
}
