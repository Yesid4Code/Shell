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
	size_t len = 0;
	ssize_t read;/*chars read by getline() */
	int i = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		write(STDOUT_FILENO,"#cisfun$ ", 9); /*printf("#cisfun$ ");*prompt */
		/*// READING PHASE \\ */
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;/*should be a continue?*/
		/* receive the command type by the user*/
		input = get_input(line, read);
		if (input == NULL)
		{
			free(input);
			continue;/*exit(EXIT_SUCCESS);*/
		}
		/*// SEARCHING PATH PHASE \\ */
		if (line[0] != '/')
		{
			input[0] = _strdup(pathtoexecute(input));
			if (!input[0])
			{
				free(input[0]), free(input);
				continue;
			}
			execute(input); /*// EXECUTE PHASE \\ */
		}
		else
			execute(input);
	}
	free(input);
	return (0);
}
